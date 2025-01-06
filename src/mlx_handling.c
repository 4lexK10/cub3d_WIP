/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:18:11 by akloster          #+#    #+#             */
/*   Updated: 2025/01/06 18:20:23 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// hooking management 

static int	key_hook(int keycode, void *param)
{
	t_data *data;

	data = (t_data *) param;
	if (keycode == ESC_KEY)
	{
		//free data
		exit(0);
	}
	else if (keycode == W_KEY)
		raycasting(data, W_KEY);
	else if (keycode == A_KEY)
		raycasting(data, A_KEY);
	else if (keycode == S_KEY)
		raycasting(data, S_KEY);
	else if (keycode == D_KEY)
		raycasting(data, D_KEY);
	else if (keycode == LEFT_ARROW)
		raycasting(data, LEFT_ARROW);
	else if (keycode == RIGHT_ARROW)
		raycasting(data, RIGHT_ARROW);
}

//int	mouse_hook(int button,int x,int y,void *param);
//{
//	if ()
//}

void	event_hook(t_data *data)
{
	void	*param;

	param = (void *) data;
	mlx_hook(data->win, KEY_DOWN, 1L<<0, &key_hook, param);	
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


