/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:05:23 by akloster          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:36 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include "mlx.h"
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"

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

typedef struct s_player
{
	float pos[2];
	float dir[2];
	float plane[2];
}	t_player;

typedef struct s_info{
	t_img	img;
	char	*path;
	int		width;
	int height;
	int c_floor[3];
	int c_sky[3];
	char	*texture_N;
	char	*texture_S;
	char	*texture_W;
	char	*texture_E;

} t_info;

typedef struct s_map
{
    char            *line;
    char            *map_line;
    char            **map_tab;
    int             width;
    int             height;
    int             line_count;
	int				count;
} t_map;

typedef struct s_data
{
	char	**map;
	t_map 	*raw_map;
	t_info	*info;
	char **file;
	t_img 		img;
	void		*mlx;
	void		*win;
	int			nbr_column;
}	t_data;



int	init_mlx(t_data *data);
int raycasting(t_data *data);
int	ft_error(char *str);
void	get_player_vector(t_data *data, t_player *player);
void	set_vector(float vector[2], float x, float y);

#endif
