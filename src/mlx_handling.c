/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:18:11 by akloster          #+#    #+#             */
/*   Updated: 2024/12/15 14:48:59 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_error("error: mlx_init failure"));
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!data->win)
		return (ft_error("error: mlx_new_window failure"));
	return (EXIT_SUCCESS);
}

