/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:27:37 by akloster          #+#    #+#             */
/*   Updated: 2024/12/15 21:15:54 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int raycasting(t_data *data)
{
	t_player	player;
	float		cameraX;
	float		ray[2];
	float		side_dist[2];
	float		delta_dist[2];
	
	int		x;
	int		map[2];

	get_player_vector(data, &player);
	// start DDA
	while (++x < WIN_WIDTH)
	{
		cameraX = 2 * (float) x / (float) WIN_WIDTH - 1;
		ray[X] = player.dir[X] + player.plane[X] * cameraX;
		ray[Y] = player.dir[Y] + player.plane[Y] * cameraX;
		map[X] = (int) player.pos[X];
		map[Y] = (int) player.pos[Y];
		
	}
}
