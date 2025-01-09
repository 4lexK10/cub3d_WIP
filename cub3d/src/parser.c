/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2025/01/08 13:44:02 by linaboumahd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_infos(t_info *infos)
{
    if(!infos->texture_E || !infos->texture_N || !infos->texture_S || !infos->texture_W)
        return (0);
    return(1);
}
int get_width(char *line)
{
    int width = 0;

    if (!line)
        return (0);
    while (line[width])
        width++;
    return (width);
}
int get_height(char **map)
{
    int height = 0;

    if (!map)
        return (0);

    while (map[height])
        height++;
    return (height);
}

int check_first_last_line(char *line)
{
    int j = 0;

    while (line[j])
    {
        if (line[j] != '1')
            return (0);
        j++;
    }
    return (1);
}

int check_borders(char *line)
{
    int len = get_width(line);

    if (line[0] != '1' || line[len - 1] != '1')
        return (0);
    return (1);
}

int check_surrounding_walls(char **map, int i, int j)
{
    if (map[i][j] == ' ')
    {
        if ((j > 0 && map[i][j - 1] != '1') ||
            (j < get_width(map[i]) - 1 && map[i][j + 1] != '1') ||
            (i > 0 && map[i - 1][j] != '1') ||
            (map[i + 1] && map[i + 1][j] != '1'))
            return (0);
    }
    return (1);
}

int check_inner_lines(char **map, int i)
{
    int j = 0;

    if (!check_borders(map[i]))
        return (0);

    while (map[i][j])
    {
        if (!check_surrounding_walls(map, i, j))
            return (0);
        j++;
    }
    return (1);
}

int check_walls(t_map *raw_map)
{
    int i = 0;
    char **map;

    map = raw_map->map_tab;
    if (!map || !map[0])
        return (0);

    if (!check_first_last_line(map[0]) || !check_first_last_line(map[get_height(map) - 1]))
        return (0); 

    i = 1;
    while (map[i + 1])
    {
        if (!check_inner_lines(map, i))
            return (0);
        i++;
    }

    return (1);
}

int check_valid_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '1' || line[i] == '0' || line[i] == 'W' ||
            line[i] == 'E' || line[i] == 'S' || line[i] == 'N')
            return (1);
        i++;
    }
    return (0); 
}

void get_raw_data(t_data *data, int fd)
{
    char *line;

    while ((line = get_next_line(fd)))
    {
        if (!get_first_info(data->raw_map, data->info, line))
        {    
            if(!check_valid_line(line) || !check_infos(data->info))
            {
                ft_error("invalid input\n");
                exit(1);
            }
            data->raw_map->map_arr = add_to_line(data->raw_map->map_arr, line);
            free(line);
        }
    }
    change_to_matrix(data->raw_map);
   
    if(!check_walls(data->raw_map))
        {
            ft_error("map not closed");
            exit(1);
        }
    close(fd);
}
