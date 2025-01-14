/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:50:53 by akloster          #+#    #+#             */
/*   Updated: 2025/01/14 17:07:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *str)
{
	size_t	res;

	res = 0;
	while (*str)	
		res += write(STDERR_FILENO, str++, 1);
	res += write(STDERR_FILENO, "\n", 1);
	if (res != (ft_strlen(str) + 1))
		return (2);
	return (EXIT_FAILURE);
}

static void	free_texture(t_texture *tex)
{
	// free path to texture
	free(tex->pixies);	
	tex->pixies = NULL;
}

void	free_all(t_data *data)
{
	// free map
	mlx_destroy_window(data->mlx, data->win);
	free_texture(&data->info.texture_N);
	free_texture(&data->info.texture_S);
	free_texture(&data->info.texture_W);
	free_texture(&data->info.texture_E);
}
