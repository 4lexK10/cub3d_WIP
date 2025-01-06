/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:05:23 by akloster          #+#    #+#             */
/*   Updated: 2025/01/06 17:37:57 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	QWERTY
# define W_KEY 0x0077
# define A_KEY 0x0061

	AZERTY
# define Z_KEY 0x007a
# define Q_KEY 0x0071
*/



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

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define X 0
# define Y 1
# define ESC_KEY 0xff1b
# define W_KEY 0x007a //is AZERTY now
# define A_KEY 0x0071 //is AZERTY now
# define S_KEY 0x0073
# define D_KEY 0x0064
# define START 0x0
# define LEFT_ARROW 0xff51
# define RIGHT_ARROW 0xff53
# define KEY_DOWN 2
# define FOV 0.66666
# define MOVE_SPEED 0.1

typedef struct s_img
{
	void	*ptr_img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_img;

typedef struct s_wall
{	
	int	h;
	int	start;
	int	end;
}	t_wall;

typedef struct	s_ray
{
	double		cameraX;
	double		cast[2];
	double		side_dist[2];
	double		delta_dist[2];
	double		perp_dist;
	int		step[2];
	int		side;
	bool		hit;
	int		map_x;
	int		map_y;
}	t_ray;

typedef struct s_player
{
	double pos[2];
	double dir[2];
	double plane[2];
}	t_player;

typedef struct s_data
{
	char	*texture_N;
	char	*texture_S;
	char	*texture_W;
	char	*texture_E;
	char		**map;
	t_player	player;
	void		*mlx;
	void		*win;
}	t_data;

int	init_mlx(t_data *data);
int	raycasting(t_data *data, int keycode);
int	ft_error(char *str);
void	get_player_vector(t_data *data, t_player *player);
int	init_frame(t_data *data, t_img *frame);
void	render_column(t_img *frame, t_ray *ray, int x);
double	absf(double nbr);
void	pre_init(t_player *player, t_ray *ray, int x);
void	set_vector(double vector[2], double x, double y);
void	rotation(t_player *player, double a);
void	move_player(char **map, t_player *player, int keycode);
void	event_hook(t_data *data);
void	print_player(t_player *player, char *msg);
void	translation(char **map, t_player *player, int keycode);

#endif
