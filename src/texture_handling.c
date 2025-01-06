/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:04 by akloster          #+#    #+#             */
/*   Updated: 2025/01/06 20:33:07 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_node(t_texture *tex, char *str)
{
	tex->colors = (t_colors *)malloc(sizeof(t_colors));
	if (!tex->colors)
		return (ft_error("error: malloc failed"));
	colors->code = str[0];
	str += 3;	
	colors->color = 0;
	while (++str)
	{
		if (ft_isdigit(*str))
			colors->color = colors->color * 16 + *str - '0';
		else
			colors->color = colors->color * 16 + 10 + *str - 'A';
	}
}

static int	get_texture(t_texture *tex)
{
	int	fd;
	char	*str;

	fd = open(tex->path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error: open failed"));
	while (ft_strncmp(get_next_line(fd), 
		"/* columns rows colors chars-per-pixel */"), 
		ft_strlen("/* columns rows colors chars-per-pixel */"))
		;
	get_next_line(fd);
	str = get_next_line(fd);
	while (str && ft_strncmp(str, "/* pixels */"), ft_strlen("/* pixels */"))
	{
		if (create_node(tex, str))
			return (EXIT_FAILURE);
		str = get_next_line(fd);
	}
	get_img() // get all chars 
}

int	init_textures(t_data *data)
{
	get_texture()
}
