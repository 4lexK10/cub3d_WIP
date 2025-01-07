/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:34 by akloster          #+#    #+#             */
/*   Updated: 2025/01/07 20:56:54 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *fake_map[] = {
"111111111111111",
"1000000000000011111111111111111111111111111111111111111111111111111111111111111",
"100000000000000000000000000000000000000000000000000000000000000000000000001",
"1100100000000011111111111111111000000000000000000000000000000000000000000111",
"10000001000000000000001111111111111100000000000000000001111111111111111111111",
"10000000000000000000011111111111110000000000000000000011111111111111111",
"1010000001000011111111111111111111110000000000000000000011111111111111111",
"1001000000000011111111111111111110000000000S00000000011111111111111111",
"1000000100100000000000111111110000000000000000000011111111111111111",
"10001000000000000000001111111111111111111111111111111111111111111111",
"1000000000100111111111111",
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
	data.info.texture_N.path = "textures/forevernevermore.xpm";
	data.info.texture_S.path = "textures/detroit_D.xpm";
	data.info.texture_E.path = "textures/rain.xpm";
	data.info.texture_W.path = "textures/u_cant_lie.xpm";	
	data.info.color_F = 0x000000;
	data.info.color_C = 0x808080;
	data.map = fake_map;
	if (init_mlx(&data) || init_textures(&data))
		return (EXIT_FAILURE);	
	raycasting(&data, START);
	event_hook(&data);	
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
