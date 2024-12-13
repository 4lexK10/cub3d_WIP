/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:50:53 by akloster          #+#    #+#             */
/*   Updated: 2024/12/13 17:23:39 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *str)
{
	while (*str)	
		write(STDERR_FILENO, str++, 1);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
