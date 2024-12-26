/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:18:11 by akloster          #+#    #+#             */
/*   Updated: 2024/12/26 00:36:46 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_error("error: mlx_init failure"));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!data->win)
		return (ft_error("error: mlx_new_window failure"));
	return (EXIT_SUCCESS);
}

int	init_frame(t_data *data, t_img *frame)
{
	frame->ptr_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!frame->ptr_img)
		return (1);
	frame->addr = mlx_get_data_addr(frame->ptr_img
		, &frame->bpp, &frame->line_length, &frame->endian);
	return (0);
}

void	put_pixel(t_img *frame, int x, int y, int color)
{
	char	*ptr_pixel;

	ptr_pixel = frame->addr + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int*)ptr_pixel = color;
}

