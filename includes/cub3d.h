/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:05:23 by akloster          #+#    #+#             */
/*   Updated: 2024/12/17 21:22:00 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
#include "mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define X 0
# define Y 1

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_img;

typedef struct	s_ray
{
	float		cameraX;
	float		cast[2];
	float		side_dist[2];
	float		delta_dist[2];
	float		perp_dist;
	int		step[2];
	int		side;
	bool		hit;
	int		map_x;
	int		map_y;
}	t_ray;

typedef struct s_player
{
	float pos[2];
	float dir[2];
	float plane[2];
}	t_player;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	int	nbr_column;
}	t_data;



int	init_mlx(t_data *data);
int raycasting(t_data *data);
int	ft_error(char *str);
void	get_player_vector(t_data *data, t_player *player);
void	set_vector(float vector[2], float x, float y);

#endif
