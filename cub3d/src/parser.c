/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2025/01/15 18:40:56 by lboumahd         ###   ########.fr       */
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
// Helper function for checking whitespace
static int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || 
            c == '\v' || c == '\f' || c == '\r');
}
int ft_strlen_int(const char *str)
{
    int len = 0;

    if (!str)
        return (0);

    while (str[len])
        len++;
    return (len);
}
int get_2d_len(char **array)
{
    int len = 0;

    if (!array)
        return (0);

    while (array[len])
        len++;
    return (len);
}
int ft_ptrptrlen(char **array)
{
    return get_2d_len(array); // Same as `get_2d_len`
}
int	valid_key(int c)
{
	if (c == '0'|| c == '1' || c == 'N'|| c == 'W'|| c == 'S'|| c == 'E')
		return (1);
	return (0);
}
int check_spaces(char **map, int index, int i, int signal)
{
    (void)signal;
    // Validate that spaces/tabs are enclosed
    if (map[index][i] == ' ' || map[index][i] == '\t')
    {
        if ((index - 1 >= 0 && map[index - 1][i] != '1' && map[index - 1][i] != ' ' && map[index - 1][i] != '\t') ||
            (index + 1 < get_2d_len(map) && map[index + 1][i] != '1' && map[index + 1][i] != ' ' && map[index + 1][i] != '\t') ||
            (i - 1 >= 0 && map[index][i - 1] != '1' && map[index][i - 1] != ' ' && map[index][i - 1] != '\t') ||
            (i + 1 < ft_strlen_int(map[index]) && map[index][i + 1] != '1' && map[index][i + 1] != ' ' && map[index][i + 1] != '\t'))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}


int middle_row_spaces(char **map, int index)
{
    int i = 0;

    // Check the first character in the row
    if (map[index][i] && (map[index][i] == ' ' || map[index][i] == '\t'))
    {
        if (check_spaces(map, index, i, 1))
            return (EXIT_FAILURE);
    }

    // Check the middle of the row
    while (map[index][i + 1])
    {
        if (map[index][i] == ' ' || map[index][i] == '\t')
        {
            if (check_spaces(map, index, i, 0))
                return (EXIT_FAILURE);
        }
        i++;
    }

    // Check the last character in the row
    if (map[index][i] && (map[index][i] == ' ' || map[index][i] == '\t'))
    {
        if (check_spaces(map, index, i, 2))
            return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

int top_row_spaces(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i][j])
    {
        if (ft_isspace(map[i][j]))
        {
            if (map[i + 1] != NULL && map[i + 1][j])
            {
                if (map[i + 1][j] != '1' && !ft_isspace(map[i + 1][j]))
                    return (EXIT_FAILURE);
                j++;
            }
            else
                return (EXIT_FAILURE);
        }
        else
            j++;
    }
    return (EXIT_SUCCESS);
}
int bot_row_spaces(char **map)
{
    int i = get_2d_len(map) - 1;
    int j = 0;

    while (map[i][j])
    {
        if (ft_isspace(map[i][j]))
        {
            if (map[i - 1] != NULL && map[i - 1][j])
            {
                if (map[i - 1][j] != '1' && !ft_isspace(map[i - 1][j]))
                    return (EXIT_FAILURE);
                j++;
            }
            else
                return (EXIT_FAILURE);
        }
        else
            j++;
    }
    return (EXIT_SUCCESS);
}

int parse_walls(char *str)
{
    int i = 0;

    if (!str || ft_strlen_int(str) == 0) // Check for empty rows
        return (EXIT_FAILURE);

    if (str[0] != '1' && str[0] != ' ' && str[0] != '\t') // First character must be part of the wall
        return (EXIT_FAILURE);

    if (str[ft_strlen_int(str) - 1] != '1' && str[ft_strlen_int(str) - 1] != ' ' && str[ft_strlen_int(str) - 1] != '\t') // Last character must be part of the wall
        return (EXIT_FAILURE);

    while (str[i])
    {
        if (!valid_key(str[i]) && str[i] != ' ' && str[i] != '\t') // Invalid characters
            return (EXIT_FAILURE);
        i++;
    }

    return (EXIT_SUCCESS);
}

// int parse_walls(char *str)
// {
//     int i = 0;

//     if (!str || ft_strlen_int(str) == 0) // Check for empty rows
//         return (EXIT_FAILURE);

//     if (str[0] != '1' || str[ft_strlen_int(str) - 1] != '1') // Check for enclosing walls
//         return (EXIT_FAILURE);

//     while (str[i])
//     {
//         if (!valid_key(str[i]) && !ft_isspace(str[i])) // Invalid characters
//             return (EXIT_FAILURE);
//         i++;
//     }

//     return (EXIT_SUCCESS);
// }

int check_walls(t_map *raw_map)
{
    int i;
    char **map;

    map = raw_map->map_tab;
    if (!map || get_2d_len(map) == 0)
    {
        ft_error("No map provided\n");
        exit(1);
    }

    // Check the first and last rows
    if (parse_walls(map[0]) || parse_walls(map[get_2d_len(map) - 1]))
        return (0);

    // Validate the middle rows
    for (i = 1; i < get_2d_len(map) - 1; i++)
    {
        if (middle_row_spaces(map, i))
            return (0);
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
    change_to_map_tab(data->raw_map);
   //check player exist
    if(!check_walls(data->raw_map))
        {
            printf("top or bot\n");
            ft_error("map not closed");
            exit(1);
        }
    close(fd);
}

// int check_first_last_line(char *line)
// {
//     int j = 0;

//     while (line[j])
//     {
//         if (line[j] != '1')
//             return (0);
//         j++;
//     }
//     return (1);
// }

// int check_borders(char *line)
// {
//     int len = get_width(line);

//     if (line[0] != '1' || line[len - 1] != '1')
//         return (0);
//     return (1);
// }

// int check_surrounding_walls(char **map, int i, int j)
// {
//     if (map[i][j] == ' ')
//     {
//         if ((j > 0 && map[i][j - 1] != '1') ||
//             (j < get_width(map[i]) - 1 && map[i][j + 1] != '1') ||
//             (i > 0 && map[i - 1][j] != '1') ||
//             (map[i + 1] && map[i + 1][j] != '1'))
//             return (0);
//     }
//     return (1);
// }

// int check_inner_lines(char **map, int i)
// {
//     int j = 0;

//     if (!check_borders(map[i]))
//         return (0);

//     while (map[i][j])
//     {
//         if (!check_surrounding_walls(map, i, j))
//             return (0);
//         j++;
//     }
//     return (1);
// }

// int check_walls(t_map *raw_map)
// {
//     int i = 0;
//     char **map;

//     map = raw_map->map_tab;
//     if (!map || !map[0])
//         return (0);

//     if (!check_first_last_line(map[0]) || !check_first_last_line(map[get_height(map) - 1]))
//         return (0); 

//     i = 1;
//     while (map[i + 1])
//     {
//         if (!check_inner_lines(map, i))
//             return (0);
//         i++;
//     }

//     return (1);
// }


