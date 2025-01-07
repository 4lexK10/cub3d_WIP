/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:50:53 by akloster          #+#    #+#             */
/*   Updated: 2025/01/07 11:28:37 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *str)
{
	while (*str)	
		write(STDERR_FILENO, str++, 1);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}

static void	free_dico(t_dictionary **dico)
{
	t_dictionary	*temp;

	while (*dico)
	{
		temp = (*dico)->next;
		free((*dico));
		*dico = temp;
	}
}

static void	free_texture(t_texture *tex)
{
	// free path to texture
	free(tex->pixels);	
	tex->pixels = NULL;
	free_dico(&tex->dico);
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
