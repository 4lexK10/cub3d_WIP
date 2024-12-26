/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2024/12/26 23:59:55 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " cub3d.h"
// check data 
    //inputs 
    //configurations 
    //

//init data


void	create_map(t_data *data, int fd)
{
	char *line;
	line = get_next_line(fd);
	while(line)
	{
		//check first inputs RGB + texture
	
		line = get_new_line(fd);
	}
}
void	init_parsing(t_data *data, int fd)
{
	//check extensions
	//createnap
	create_map(data, fd);
}
void	init_data(t_data *data)
{
	data->map = NULL;
	data->height = 0;
	data->width = 0;
	init_info(data->info);
	
}