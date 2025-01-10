/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:28:40 by akloster          #+#    #+#             */
/*   Updated: 2025/01/09 22:55:05 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	no_put_pixel(t_img *frame, int x, int y, unsigned int color)
{
	char	*ptr_pixel;

	ptr_pixel = (void *)frame->data + (y * frame->line_length
		+ x * (frame->bpp / 8));
	//if (x == 10)
	//	printf("%u\n", color);
	*(unsigned int*)ptr_pixel = color;
}

static void	put_pixel(t_img *frame, int x, int y, unsigned int color)
{
	if (x >= 0 && y >= 0 && x <= frame->width && y >= frame->height
		&& ((y * frame->width + x) <= (frame->width * frame->height - 1)))
		frame->data[y * frame->width + x] = color;
}

static unsigned int	get_code(t_dictionary *dico, char c)
{
	while (dico && dico->code != c)
		dico = dico->next;
	if (dico)
		return (dico->color);
	return (0x000000);
}

static unsigned int	not_get_color(t_data *data, t_ray *ray, int x, int y)
{
	char	c;

	if (ray->side && data->player.dir[Y] < 0)
	{
		c = data->info.texture_S.pixels[y * TEX_HEIGHT + x];
		return (get_code(data->info.texture_S.dico, c));
	}
	else if (ray->side && data->player.dir[Y] > 0)
	{
		c = data->info.texture_N.pixels[y * TEX_HEIGHT + x];
		return (get_code(data->info.texture_N.dico, c));
	}
	else if (!ray->side && data->player.dir[X] > 0)
	{
		c = data->info.texture_W.pixels[y * TEX_HEIGHT + x];
		return (get_code(data->info.texture_W.dico, c));
	}
	else if (!ray->side && data->player.dir[X] < 0)
	{
		c = data->info.texture_E.pixels[y * TEX_HEIGHT + x];
		return (get_code(data->info.texture_E.dico, c));
	}
	
}

static unsigned int	get_color(t_data *data, t_ray *ray, int x, int y)
{
	char	c;

	if (ray->side && ray->cast[Y] < 0)
		return (data->info.texture_S.pixies[y * 100 + x]);
	else if (ray->side && ray->cast[Y] > 0)
		return (data->info.texture_N.pixies[y * 100 + x]);
	else if (!ray->side && ray->cast[X] > 0)
		return (data->info.texture_W.pixies[y * 100 + x]);
	else if (!ray->side && ray->cast[X] < 0)
		return (data->info.texture_E.pixies[y * 100 + x]);
}

static void	calibrate_texture(t_data *data, t_wall *wall, t_ray *ray)
{
	if (ray->side)
		wall->x = data->player.pos[X] + ray->perp_dist * ray->cast[X];
	else
		wall->x = data->player.pos[Y] + ray->perp_dist * ray->cast[Y];
	wall->x -= floor(wall->x);
	wall->tex_X = (int) (wall->x * (double) (TEX_WIDTH));
	if (!ray->side && ray->cast[X] > 0) 
		wall->tex_X = TEX_WIDTH - wall->tex_X - 1;
	if (ray->side && ray->cast[Y] < 0)
		wall->tex_X = TEX_WIDTH - wall->tex_X - 1;
	wall->step = 1.0 * TEX_HEIGHT / wall->h;
	wall->pos = (wall->start - WIN_HEIGHT / 2 + wall->h / 2) * wall->step;	
}

void	render_column(t_data *data, t_img *frame, t_ray *ray, int x)
{
	t_wall		wall;
	int		y;

	wall.h = (int) (WIN_HEIGHT / ray->perp_dist);
	//if (/*x == 1 || */x == WIN_WIDTH / 2/* || x == WIN_WIDTH - 1*/)
	//	printf("wall height: %d\nperp_dist: %f\n", wall.h, ray->perp_dist);
	wall.start = -wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.start < 0)
		wall.start = 0;
	wall.end = wall.h / 2 + WIN_HEIGHT / 2;
	if (wall.end >= WIN_HEIGHT)
		wall.end = WIN_HEIGHT - 1;
	calibrate_texture(data, &wall, ray);
	y = wall.start;
	while (y <= wall.end)
	{
		wall.tex_Y = (int) wall.pos & (TEX_HEIGHT - 1);
		//if (x == 10)
			//printf("%2f\n", wall.step);
		wall.pos += wall.step;
		put_pixel(frame, x, y, get_color(data, ray, wall.tex_X, wall.tex_Y));
		++y;
		//if (x == WIN_WIDTH / 2)
		//	printf("side: %d\ndir (%F, %F)\n\n", ray->side, data->player.dir[X], data->player.dir[Y]);
	}
	y = -1;
	while (++y < wall.start)
		put_pixel(frame, x, y, data->info.color_F);
	y = wall.end;
	while (++y < WIN_HEIGHT)
		put_pixel(frame, x, y, data->info.color_C);
}



