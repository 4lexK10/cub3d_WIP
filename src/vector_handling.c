/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:03 by akloster          #+#    #+#             */
/*   Updated: 2024/12/15 19:25:22 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_vector(float vector[2], float x, float y)
{
	vector[X] = x;
	vector[Y] = y;
}

static void	set_FOV(t_player *player, char dir)
{
	
	if (dir == 'N')
		set_vector(player->dir, 0.0, 1.0);
	if (dir == 'E')	
		set_vector(player->dir, 1.0, 0.0);
	if (dir == 'S')	
		set_vector(player->dir, 0.0, -1.0);
	if (dir == 'W')	
		set_vector(player->dir, -1.0, 0.0);
	if (player->dir[X] == 0)
		set_vector(player->plane, 0.66, 0);
	else
		set_vector(player->plane, 0.0, 0.66);
}

void	get_player_vector(t_data *data, t_player *player)
{	
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (ft_isdigit(data->map[++i + ++j * data->nbr_column]))
		;
	set_vector(player->pos, (float) i, (float) j);
	set_FOV(player, data->map[++i + ++j * data->nbr_column]);
}
