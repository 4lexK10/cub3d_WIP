/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:44 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:44 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (4);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (0);
	printf("ft_isalnum -> %d\n", ft_isalnum(*av[1]));
	printf("isalnum    -> %d\n", isalnum(*av[1]));
	return (0);
}
int main(void)
{
	//unsigned char c = "c";
	printf("isalnum    -> %d\n", isalnum(' '));
	printf("ft_isalnum -> %d\n", ft_isalnum(' '));
	return (0);
} */