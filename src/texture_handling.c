/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:04 by akloster          #+#    #+#             */
/*   Updated: 2025/01/09 22:27:22 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	create_node(t_dictionary **head, char *str)
{
	t_dictionary	*new;
	t_dictionary	*temp;
	int		i;
	
	new = (t_dictionary *)malloc(sizeof(t_dictionary));
	if (!new)
		return (ft_error("error: malloc failed"));
	if (!(*head))
		*head = new;
	new->code = str[1];
	//printf("\n\nstr %s", str);
	new->color = 0;
	i = 4;
	while (str[++i])
	{
		//printf("%ccreat nod-> %u\n",*str, new->color);
		if (ft_isdigit(str[i]))
		{
			new->color = new->color * 16 + str[i] - '0';
		}
		else
		{
			new->color = new->color * 16 + 10 + str[i] - 'A';
		}
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

	tex->pixels = (char *)malloc((TEX_WIDTH * TEX_HEIGHT) + 1);
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

static int	load_img(t_data *data, t_texture *tex, char *path)
{
	t_img	img;
	int	x;
	int	y;

	y = -1;
	img.ptr_img = mlx_xpm_file_to_image(data->mlx, path, &img.width, &img.height);
	if (!img.ptr_img)
		return (ft_error("error: malloc failed"));
	img.data = (int *)mlx_get_data_addr(img.ptr_img, &img.bpp, &img.line_length, &img.endian);
	tex->pixies = (int *)malloc(img.width * img.height * sizeof(int));
	printf("tex H: %d\ntex W: %d\n", img.height, img.width);
	if (!tex->pixies)
		return (mlx_destroy_image(data->mlx, img.ptr_img), ft_error("error: malloc failed"));
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			tex->pixies[y * img.width + x] = img.data[y * img.width + x];
	}
	mlx_destroy_image(data->mlx, img.ptr_img);
	return (EXIT_SUCCESS);
}

static int	get_texture(t_data *data, t_texture *tex)
{
	int		fd;
	char		*str;

	fd = open(tex->path, O_RDONLY);
	if (fd == -1)
		return (ft_error("error: open failed"));
//	for (t_dictionary *temp = tex->dico; temp; temp = temp->next)
//		printf("%c -> %u\n", temp->code, temp->color);
	if (load_img(data, tex, tex->path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	not_get_texture(t_texture *tex)
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
//	for (t_dictionary *temp = tex->dico; temp; temp = temp->next)
//		printf("%c -> %u\n", temp->code, temp->color);
	return (EXIT_SUCCESS);
}


int	init_textures(t_data *data)
{
	if (get_texture(data, &data->info.texture_N)
		|| get_texture(data, &data->info.texture_S)
		|| get_texture(data, &data->info.texture_E)
		|| get_texture(data, &data->info.texture_W))
		return (EXIT_FAILURE);
}




