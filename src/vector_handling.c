/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:03 by akloster          #+#    #+#             */
/*   Updated: 2024/12/13 18:54:41 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_vector(float vector[2], float x, float y)
{
	vector[X] = x;
	vector[Y] = y;
}

static void	set_FOV(t_vector *vector, char dir)
{	
	
	if (dir == 'N')
		set_vector(vector->dir, 0.0, 1.0);
	if (dir == 'E')	
		set_vector(vector->dir, 1.0, 0.0);
	if (dir == 'S')	
		set_vector(vector->dir, 0.0, -1.0);
	if (dir == 'W')	
		set_vector(vector->dir, -1.0, 0.0);
	if (vector->dir[X] == 0)
		set_vector(vector->plane, 0.66, 0);
	else
		set_vector(vector->plane, 0.0, 0.66);
}

void	get_player_vector(t_data *data, t_vector *vector)
{	
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (ft_isdigit(data->map[++i + ++j * data->nbr_column]))
		;
	set_vector(vector->pos, (float) i, (float) j);
	set_FOV(vector, data->map[++i + ++j * data->nbr_column]);
}