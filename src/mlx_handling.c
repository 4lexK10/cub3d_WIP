/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:18:11 by akloster          #+#    #+#             */
/*   Updated: 2024/12/12 18:47:16 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_error("error: mlx_init failure"));
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data->win)
		return (ft_error("error: mlx_new_window failure"));
}

