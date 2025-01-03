/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:34 by akloster          #+#    #+#             */
/*   Updated: 2025/01/03 10:51:14 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *fake_map[] = {
"111111111111111",
"100000000000001",
"110000000000001",
"100010001000001",
"101000000000001111",
"100000000000000001",
"10000000000W001111",
"1000000000000111",
"111111111111111"};


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
	raycasting(&data, START);
	event_hook(&data);	
	mlx_loop(data.mlx);
}
