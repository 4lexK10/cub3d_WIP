/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:58:30 by akloster          #+#    #+#             */
/*   Updated: 2025/01/06 10:09:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	absf(double nbr)
{// should i overflow check from min double to max double or fuck it? most prob fuck it
	if (nbr < 0)
		return (nbr * -1.0);
	return (nbr);
}

void	rotation(t_player *player, double a)
{
	double	x;
	double	y;

	x = player->dir[X];
	y = player->dir[Y];
	player->dir[X] = cosf(a) * x - sinf(a) * y;
	player->dir[Y] = sinf(a) * x + cosf(a) * y;
}

void	translation(char **map, t_player *player, int keycode)
{
	if (keycode == W_KEY && map[(int) (player->pos[Y] + player->dir[Y] * MOVE_SPEED)]
		[(int) (player->pos[X] + player->dir[X] * MOVE_SPEED)] != '1')
		set_vector(player->pos, player->pos[X] + player->dir[X] 
			* MOVE_SPEED, player->pos[Y] + player->dir[Y] * MOVE_SPEED);
	else if (keycode == S_KEY && map[(int) (player->pos[Y] - player->dir[Y] * MOVE_SPEED)]
		[(int) (player->pos[X] - player->dir[X] * MOVE_SPEED)] != '1')
		set_vector(player->pos, player->pos[X] - player->dir[X]
			* MOVE_SPEED, player->pos[Y] - player->dir[Y] * MOVE_SPEED);
	else if (keycode == A_KEY && map[(int) (player->pos[Y] - player->dir[X] * MOVE_SPEED)]
		[(int) (player->pos[X] + player->dir[Y] * MOVE_SPEED)] != '1')
		set_vector(player->pos, player->pos[X] + player->dir[Y]
			* MOVE_SPEED, player->pos[Y] - player->dir[X] * MOVE_SPEED);
	else if (keycode == D_KEY && map[(int) (player->pos[Y] + player->dir[X] * MOVE_SPEED)]
		[(int) (player->pos[X] - player->dir[Y] * MOVE_SPEED)] != '1')
		set_vector(player->pos, player->pos[X] - player->dir[Y]
			* MOVE_SPEED, player->pos[Y] + player->dir[X] * MOVE_SPEED);
}

void	set_vector(double vector[2], double x, double y)
{
	vector[X] = x;
	vector[Y] = y;
}

void	pre_init(t_player *player, t_ray *ray, int x)
{
	ray->hit = false;
	ray->cameraX = 2 * (double) x / (double) WIN_WIDTH - 1;
	ray->cast[X] = player->dir[X] + player->plane[X] * ray->cameraX;
	ray->cast[Y] = player->dir[Y] + player->plane[Y] * ray->cameraX;
	ray->map_x = (int) player->pos[X];
	ray->map_y = (int) player->pos[Y];
	ray->delta_dist[X] = 1e30;
	ray->delta_dist[Y] = 1e30;
}

