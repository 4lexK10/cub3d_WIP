/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:06:11 by lboumahd          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:36 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *add_to_line(char *map_line, char *line)
{
    int		size;
	int		i;
	char	*tab;
    
    i = 0;
	size = get_size (map_line, line);
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (map_line && map_line[i])
	{
		tab[i] = map_line[i];
		i++;
	}
	while (*line)
	{
		tab[i] = *line;
		i++;
		line++;
	}
	tab[size] = ';';
	tab[size + 1] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

void    change_to_matrix(t_map *map)
{
    map->map_tab = ft_split(map->map_line, ";");
    resize_map(map);
    free(map->map_line);
    map->map_line = NULL;
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