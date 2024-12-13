/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:34 by akloster          #+#    #+#             */
/*   Updated: 2024/12/13 16:55:44 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char fake_map[] = 
{1,1,1,1,1,1,1,1,1,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,'N',0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,0,0,0,0,0,0,0,0,1
,1,1,1,1,1,1,1,1,1,1};

int	main(int ac, char **av)
{
	t_data	data;

	(void) av;
	if (ac != 2)
		return (ft_error("error: incorrect number of arguments"));
	ft_memset(&data, 0, sizeof(t_data));
	/*if (parser(av[1]), &data)
		return (EXIT_FAILURE);*/
	data.map = fake_map;
	if (init_mlx(&data))
		return (EXIT_FAILURE);	
	raycasting(&data);
}


