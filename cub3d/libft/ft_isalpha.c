/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:52 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
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
	printf("ft_isalpha -> %d\n", ft_isalpha(*av[1]));
	printf("isalpha    -> %d\n", isalpha(*av[1]));
	return (0);
}
int main(void)
{
	//unsigned char c = "c";
	printf("isalpha    -> %d\n", isalpha(-2147483648));
	printf("ft_isalpha -> %d\n", ft_isalpha(-2147483648));
	return (0);
} */