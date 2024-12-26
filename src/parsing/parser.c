/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:36 by lboumahd          #+#    #+#             */
/*   Updated: 2024/12/27 00:35:57 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check data 
    //inputs 
    //configurations 
    //

//init data
void	parse_map(t_data *data, int fd)
{
	char *line;
    int i;

    i = 0;
	line = get_next_line(fd);
    //check first inputs RGB + texture
        //get rid of white space 
        //get rid of the 6 first lines
	while(line)
	{
        //join thelines with a delimiter of choice 
        if(line[i] == '\n')
     
		line = get_new_line(fd);
	}
       data->map = ft_split 
}
void	init_parsing(t_data *data, int fd)
{
	//check extensions
	//createnap
	parse_map(data, fd);
}
void	init_data(t_data *data)
{
	data->map = NULL;
	data->height = 0;
	data->width = 0;
	init_info(data->info);
	
}