/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2024/12/28 15:25:36 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_number_of_lines(char *path)
{
    int     fd;
    char    *line;
    int     line_count;

    line_count = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
       //error
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

int get_first_info(t_map *map, char *line)
{
    //get_ infos TXT RGB 
}
void get_raw_data(t_map *map, int fd)
{
    char *line;

    while ((line = get_next_line(fd)))
    {
        if (line[0] == '\n')
            line[0] = ' ';
        if(!check_valid_line(line))
            ft_error("invalid char\n");
        if(!get_first_info(map, line))
            map->map_line = add_to_line(map->map_line, line); 
        free(line);
    }
    change_to_matrix(map);
    if(!check_walls(map->map_tab))
        ft_error("map not closed");
    close(fd);
}
