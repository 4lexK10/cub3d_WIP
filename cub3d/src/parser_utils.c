/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:06:11 by lboumahd          #+#    #+#             */
/*   Updated: 2025/01/08 13:17:05 by linaboumahd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_size(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}
char    *add_to_line(char *map_line, char *line)
{
    int		size;
	int		i;
	char	*arr;
    
    i = 0;
	if (line[0] == '\n')
            line[0] = ' ';
	size = get_size(map_line) + get_size(line);
	arr = malloc(sizeof(char) * size + 2);
	if (arr == NULL)
		return (NULL);
	while (map_line && map_line[i])
	{
		arr[i] = map_line[i];
		i++;
	}
	while (*line)
		arr[i++] = *line++;
	arr[size] = ';';
	arr[size + 1] = '\0';
	if (map_line)
		free(map_line);
	return (arr);
}

void    change_to_matrix(t_map *map)
{
    map->map_tab = ft_split(map->map_arr, ';');
    //resize_map(map);
    free(map->map_arr);
    map->map_arr = NULL;
    //fiix size???
}

/*
//making check data easyyyyyy
void fix_size_map(t_map *map)
{
    int i = 0;

    set_size_data(map, map->map_tab, 0, 0);
    if (map->height == 0 && map->width == 0)
       ft_error("Error\nOnly one player is required on the map\n");

    while (map->map_tab[i])
    {
        if (ft_strlen_cub3d(map->map_tab[i]) < map->width)
        {
            map->map_tab[i] = ft_resize_line(map->map_tab[i], map->width);
            if (!map->map_tab[i])
               ft_error("Malloc error\n");
        }
        i++;
    }
}

*/