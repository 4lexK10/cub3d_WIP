/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:34 by akloster          #+#    #+#             */
/*   Updated: 2024/12/12 12:58:42 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("error: incorrect number of arguments"))
	ft_memset(&data, 0, sizeof(t_data));
	if (parser(av[1]), &data)
		return (EXIT_FAILURE);
	if (init_img	)
	
}

