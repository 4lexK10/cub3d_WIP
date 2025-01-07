/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:02 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:48:02 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (0);
	printf("ft_isdigit -> %d\n", ft_isdigit(*av[1]));
	printf("isdigit    -> %d\n", isdigit(*av[1]));
	return (0);
}
int main(void)
{
	//unsigned char c = "c";
	printf("ft_isdigit -> %d\n", ft_isdigit('0'));
	printf("isdigit    -> %d\n", isdigit('0'));
	return (0);   
} */