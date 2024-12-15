/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:27:37 by akloster          #+#    #+#             */
/*   Updated: 2024/12/15 18:47:47 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int raycasting(t_data *data)
{
	t_player	player;
	float		cameraX;
	float		ray[2];	
	int		x;

	get_player_vector(data, &player);
	// start DDA
	while (++x < WIN_WIDTH)
	{
		cameraX = 2 * (float) x / (float) WIN_WIDTH;
	}
}
