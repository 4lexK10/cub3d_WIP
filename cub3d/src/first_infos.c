/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:58:01 by linaboumahd       #+#    #+#             */
/*   Updated: 2025/01/07 00:17:28 by linaboumahd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *get_texture(char **split_line)
{
    char    *path;
    int     path_len;

    if (!split_line[1] || split_line[2])
    {
        free_split(split_line);
        ft_error("Error: Invalid texture format\n");
    }
    path = ft_strdup(split_line[1]);
    if (!path)
    {
        free_split(split_line);
        ft_error("Error: Memory allocation failed\n");
    }
    path_len = ft_strlen(path);
    if (path[path_len - 1] == '\n')
        path[path_len - 1] = '\0';
    return (path);
}

int get_first_info(t_info *info, char *line)
{
    char **split_line;

    if (!line || (line[0] == '\n' && !line[1]))
        return (1);
    split_line = ft_split(line, ' ');
    if (split_line[0] && !ft_strncmp(split_line[0], "NO", 3))
        info->texture_N = get_texture(split_line);
    else if (split_line[0] && !ft_strncmp(split_line[0], "SO", 3))
        info->texture_S = get_texture(split_line);
    else if (split_line[0] && !ft_strncmp(split_line[0], "WE", 3))
        info->texture_W = get_texture(split_line);
    else if (split_line[0] && !ft_strncmp(split_line[0], "EA", 3))
        info->texture_E = get_texture(split_line);
    // else if (split_line[0] && !ft_strcmp(split_line[0], "F"))
    //     info->rgb_floor = get_rgb(split_line);
    // else if (split_line[0] && !ft_strcmp(split_line[0], "C"))
    //     info->rgb_sky = get_rgb(split_line);
    else
    {
        free_split(split_line);
        return (0);
    }
    free_split(split_line); 
    return (1);
}
