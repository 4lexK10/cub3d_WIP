/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:27:37 by akloster          #+#    #+#             */
/*   Updated: 2024/12/26 18:28:15 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	absf(float nbr)
{// should i overflow check from min float to max float or fuck it? most probs fuck it
	if (nbr < 0)
		return (nbr * -1.0);
	return (nbr);
}

static void	pre_init(t_player *player, t_ray *ray, int x)
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

static void	init_ray(t_player *player, t_ray *ray, int x)
{
	pre_init(player, ray, x);
	if (ray->cast[X] != 0)
		ray->delta_dist[X] = absf(1.0 / ray->cast[X]);
	if (ray->cast[Y] != 0)
		ray->delta_dist[Y] = absf(1.0 / ray->cast[Y]);
	if (ray->cast[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (player->pos[X] - ray->map_x) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (player->pos[X] + 1 - player->pos[X]) * ray->delta_dist[X];
	}
	if (ray->cast[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (player->pos[Y] - ray->map_y) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (player->pos[Y] + 1 - player->pos[Y]) * ray->delta_dist[Y];
	}
}

static void	dda(t_data *data, t_player *player, t_ray *ray)
{
	if (ray->side_dist[X] < ray->side_dist[Y])
	{
		ray->side_dist[X] += ray->delta_dist[X];
		ray->map_x += ray->step[X];
		ray->side = 0;
	}
	else
	{
		ray->side_dist[Y] += ray->delta_dist[Y];
		ray->map_y += ray->step[Y];
		ray->side = 1;
	}
	if (data->map[ray->map_y][ray->map_x] != '0')
		ray->hit = true;
}

int raycasting(t_data *data)
{
	t_player	player;
	t_ray		ray;
	t_img		frame;
	int		x;

	get_player_vector(data, &player);
	if (init_frame(data, &frame))
		return (ft_error("Error: mlx\n"));
	while (++x < WIN_WIDTH)
	{
		init_ray(&player, &ray, x);
		while (!ray.hit)
			dda(data, &player, &ray);
		ray.perp_dist = ray.side_dist[X] - ray.delta_dist[X];
		if (ray.side)
			ray.perp_dist = ray.side_dist[Y] - ray.delta_dist[Y];
		render_column(&frame, &ray, x);
	}
	mlx_put_image_to_window(data->mlx, data->win, frame.ptr_img, 0, 0);
	mlx_destroy_image(data->mlx, frame.ptr_img);
	return (0);
}





