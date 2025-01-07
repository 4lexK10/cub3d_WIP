/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2025/01/07 00:17:25 by linaboumahd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void get_raw_data(t_data *data, int fd)
{
    char *line;
 
    while ((line = get_next_line(fd)))
    {
        if(!get_first_info(data->info, line))
        {
            // if(!check_valid_line(line))
            //     ft_error("invalid char\n");
            data->raw_map->map_arr = add_to_line(data->raw_map->map_arr, line);
        }
        free(line);
    }
    change_to_matrix(data->raw_map);
    // if(!check_walls(map->map_tab))
    //     ft_error("map not closed");
    close(fd);
}
