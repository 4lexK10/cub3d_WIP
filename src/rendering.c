/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:28:40 by akloster          #+#    #+#             */
/*   Updated: 2025/01/07 09:45:40 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_img *frame, int x, int y, int color)
{
	char	*ptr_pixel;

	ptr_pixel = frame->addr + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int*)ptr_pixel = color;
}

void	render_column(t_img *frame, t_ray *ray, int x)
{
	t_wall	wall;
	int	y;

	wall.h = (int) (WIN_HEIGHT / ray->perp_dist);
	//if (/*x == 1 || */x == WIN_WIDTH / 2/* || x == WIN_WIDTH - 1*/)
	//	printf("wall height: %d\nperp_dist: %f\n", wall.h, ray->perp_dist);
	wall.start = -wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.start < 0)
		wall.start = 0;
	wall.end = wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.end >= WIN_HEIGHT)
		wall.end = WIN_HEIGHT - 1;
	y = wall.start;
	while (y <= wall.end)
	{
		if (ray->side)
			put_pixel(frame, x, y++, 0x808080);
		else
			put_pixel(frame, x, y++, 0xFFFFFF);
	}
}

