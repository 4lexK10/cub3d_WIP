/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:04 by akloster          #+#    #+#             */
/*   Updated: 2025/01/07 11:28:29 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_node(t_dictionary **head, char *str)
{
	t_dictionary	*new;
	t_dictionary	*temp;

	new = (t_dictionary *)malloc(sizeof(t_dictionary));
	if (!new)
		return (ft_error("error: malloc failed"));
	if (!(*head))
		*head = new;
	new->code = str[1];
	str += 4;
	new->color = 0;
	while (++(*str))
	{
		if (ft_isdigit(*str))
			new->color = new->color * 16 + *str - '0';
		else
			new->color = new->color * 16 + 10 + *str - 'A';
	}
	new->next = NULL;
	temp = *head;
	while (temp && temp->next != NULL)
		temp = temp->next;
	if (temp != new)
		temp->next = new;
	return (EXIT_SUCCESS);
}

static void safe_gnl(char **str, int fd)
{
	free(*str);
	*str = get_next_line(fd);
}

static int	get_img(t_texture *tex, int fd)
{
	char	*str;
	int	i;
	int	j;

	tex->pixels = (char *)malloc(TEX_WIDTH * TEX_HEIGHT);
	if (!tex->pixels)
		return (ft_error("error: malloc failed"));
	str = get_next_line(fd);
	i = -1;
	while (str && ft_strncmp(str, "};", 2))
	{
		j = 0;
		while (str[++j] != '"')
			tex->pixels[++i] = str[j];
		safe_gnl(&str, fd);
	}
	tex->pixels[++i] = '\0';
	free(str);
	str = NULL;
	return (EXIT_SUCCESS);
}

static int	get_texture(t_texture *tex)
{
	int		fd;
	char		*str;

	fd = open(tex->path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error: open failed"));
	str = get_next_line(fd);
	while (str && ft_strncmp(str, 
		"/* columns rows colors chars-per-pixel */", 
		ft_strlen("/* columns rows colors chars-per-pixel */")))
		safe_gnl(&str, fd);
	safe_gnl(&str, fd);
	safe_gnl(&str, fd);
	tex->dico = NULL;
	while (str && ft_strncmp(str, "/* pixels */", ft_strlen("/* pixels */")))
	{
		if (create_node(&tex->dico, str))
			return (EXIT_FAILURE);
		safe_gnl(&str, fd);
	}
	free(str);
	str = NULL;
	if (get_img(tex, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_textures(t_data *data)
{
	if (get_texture(&data->info.texture_N)
		|| get_texture(&data->info.texture_S)
		|| get_texture(&data->info.texture_E)
		|| get_texture(&data->info.texture_W))
		return (EXIT_FAILURE);
}




