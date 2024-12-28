/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:18:11 by akloster          #+#    #+#             */
/*   Updated: 2024/12/28 02:54:16 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// hooking management 

int	key_hook(int keycode, void *param);
{
	(t_data *) param;

	if (keycode == ESC_KEY)
	{
		//free data
		exit(0);
	}
	if (keycode == W_KEY)
		raycasting(data, W_KEY);
	if (keycode == A_KEY)
		raycasting(data, A_KEY);
	if (keycode == S_KEY)
		raycasting(data, S_KEY);
	if (keycode == D_KEY)
		raycasting(data, D_KEY);
}

//int	mouse_hook(int button,int x,int y,void *param);
//{
//	if ()
//}

void	event_hook(t_data *data)
{
	
}

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


