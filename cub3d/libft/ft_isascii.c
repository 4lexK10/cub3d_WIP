/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:57 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:57 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (0);
	// printf("ft_isascii -> %d\n", ft_ascii(*av[1]));
	printf("isascii    -> %d\n", isascii(*av[1]));
	return (0);
}
int main(void)
{
	// unsigned char c = -208;
	printf("isascii    -> %d\n", isascii(-209));
	printf("ft_isascii -> %d\n", ft_isascii(-209));
	return (0);
} */