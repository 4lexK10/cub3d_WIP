/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:05:23 by akloster          #+#    #+#             */
/*   Updated: 2024/12/12 18:48:23 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_img;

typedef struct s_data
{
	char	*map;
	void	*mlx;
	void	*win
}	t_data;

int	init_mlx(t_data *data);

#endif
