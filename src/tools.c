/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:58:30 by akloster          #+#    #+#             */
/*   Updated: 2025/01/03 12:58:17 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	absf(float nbr)
{// should i overflow check from min float to max float or fuck it? most prob fuck it
	if (nbr < 0)
		return (nbr * -1.0);
	return (nbr);
}

void	rotation(t_player *player, float a)
{
	float	x;
	float	y;

	x = player->dir[X];
	y = player->dir[Y];
	player->dir[X] = cosf(a) * x - sinf(a) * y;
	player->dir[Y] = sinf(a) * x + cosf(a) * y;
}

void	set_vector(float vector[2], float x, float y)
{
	vector[X] = x;
	vector[Y] = y;
}

void	pre_init(t_player *player, t_ray *ray, int x)
{
	ray->hit = false;
	ray->cameraX = 2 * (float) x / (float) WIN_WIDTH - 1;
	ray->cast[X] = player->dir[X] + player->plane[X] * ray->cameraX;
	ray->cast[Y] = player->dir[Y] + player->plane[Y] * ray->cameraX;
	ray->map_x = (int) player->pos[X];
	ray->map_y = (int) player->pos[Y];
	ray->delta_dist[X] = 1e30;
	ray->delta_dist[Y] = 1e30;
}

