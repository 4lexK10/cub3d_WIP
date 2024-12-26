/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:28:40 by akloster          #+#    #+#             */
/*   Updated: 2024/12/26 01:39:50 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	render_column(t_img *frame, t_ray *ray, int x)
{
	t_wall	wall;
	int	y;

	wall.h = (int) (WIN_HEIGHT / ray->perp_dist);
	wall.start = -wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.start < 0)
		wall.start = 0;
	wall.end = wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.end >= WIN_HEIGHT)
		wall.end = WIN_HEIGHT - 1;
	y = wall.start;
	while (y <= wall.end)
		put_pixel(frame, x, y++, 0xFFFFFFFF);
}

