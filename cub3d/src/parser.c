/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2025/01/07 21:16:37 by linaboumahd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_infos(t_info *infos)
{
    //check validity path
    if(!infos->texture_E || !infos->texture_N || !infos->texture_S || !infos->texture_W)
        return (0);
    //cjheck validity rgb
    return(1);
}
int get_number_of_lines(char *path)
{
    int     fd;
    char    *line;
    int     line_count;

    line_count = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
       ft_error("erro open");
    line = get_next_line(fd);
    while (line)
    {
        line_count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (line_count);
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
    // if(!check_walls(map->map_tab))
    //     ft_error("map not closed");
    close(fd);
}
