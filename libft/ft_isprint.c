/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:09 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:48:09 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	if (c >= '0' && c <= '9')
		return (4);
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) 
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (16);
	if (c == 32)
		return (64);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (0);
	printf("ft_isprint -> %d\n", ft_isprint(*av[1]));
	printf("isprint    -> %d\n", isprint(*av[1]));
	return (0);
}
int main(void)
{
	unsigned char c = "c";
	printf("ft_isprint -> %d\n", ft_isprint(0));
	printf("isprint    -> %d\n", isprint(0));
	return (0);   
} */