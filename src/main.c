/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:34 by akloster          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:36 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_info(t_info *info)
{
	info->c_floor[0] = -1;
	info->c_floor[1] = -1;
	info->c_floor[2] = -1;
	info->c_sky[0] = -1;
	info->c_sky[1] = -1;
	info->c_sky[2] = -1;
	info->texture_E = NULL;
	info->texture_N = NULL;
	info->texture_S = NULL;
	info->texture_W = NULL;
}
void	init_parsing(t_data *data, int fd)
{
	//check existence + validity of files 
	get_raw_data(data->raw_map, fd);//fill fd into **raw_map
	
	//check validity  RGB - Txture - map
	//player position a voir avec alberto 
}
void	init_data(t_data *data, char *path)
{
	data->map = data->raw_map->map_tab; // a voir 
	data->raw_map->line_count = get_number_of_lines(path);
	data->raw_map->height = 0;
	data->raw_map->width = 0;
	init_info(data->info);
}
int	main(int ac, char **av)
{
	t_data data;
	int	fd;

	//ac check 
	fd = open(av[1], "r");
	//fd error 
	init_data(&data, av[1]);
	init_parsing(&data, fd);
	//free + close fd
}
