/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:03 by akloster          #+#    #+#             */
/*   Updated: 2024/12/27 00:02:28 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_vector(float vector[2], float x, float y)
{
	vector[X] = x;
	vector[Y] = y;
}

static void	set_FOV(t_player *player, char dir)
{
	if (dir == 'N')
		set_vector(player->dir, 0.0, 1.0);
	if (dir == 'E')	
		set_vector(player->dir, -1.0, 0.0);
	if (dir == 'S')	
		set_vector(player->dir, 0.0, -1.0);
	if (dir == 'W')	
		set_vector(player->dir, 1.0, 0.0);
	set_vector(player->plane, 0.0, 0.66);
	if (player->dir[X] == 0)
		set_vector(player->plane, 0.66, 0);
}

static void	get_pos(char **map, int *i, int *j)
{	
	*i = -1;
	while (map[++(*i)])
	{
		*j = -1;
		while (map[*i][++(*j)])
		{
			if (ft_isalpha(map[*i][*j]))
				return ;
		}
	}
}

static void	check_wall(char **map, t_player *player, int i, int j)
{
	if (map[i][j - 1] == '1')
		player->pos[X] += 0.01;
	if (map[i - 1][j] == '1')
		player->pos[Y] += 0.01;
}

void	get_player_vector(t_data *data, t_player *player)
{
	int	i;
	int	j;	

	get_pos(data->map, &i, &j);
	set_vector(player->pos, (float) j, (float) i);
	check_wall(data->map, player, i, j);
	set_FOV(player, data->map[i][j]);
}


