/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:59:50 by akloster          #+#    #+#             */
/*   Updated: 2023/11/07 14:41:32 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_positive(int n)
{
	int		i;
	int		nb;
	int		size;
	char	*str_nb;

	nb = n;
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		++size;
	}
	str_nb = (char *)malloc(size * sizeof(char) + 1);
	if (!str_nb)
		return (NULL);
	i = size - 1;
	while (n > 0)
	{
		str_nb[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	str_nb[size] = '\0';
	return (str_nb);
}

static char	*itoa_negative(int n)
{
	int		i;
	int		nb;
	int		size;
	char	*str_nb;

	nb = n;
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		++size;
	}
	str_nb = (char *)malloc(size * sizeof(char) + 2);
	if (!str_nb)
		return (NULL);
	i = size;
	while (n > 0)
	{
		str_nb[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	str_nb[0] = '-';
	str_nb[size + 1] = '\0';
	return (str_nb);
}

char	*ft_itoa(int n)
{
	char	*min_int;
	char	*nb;

	if (n > 0)
		return (itoa_positive(n));
	if (n < 0 && n != -2147483648)
		return (itoa_negative(-n));
	if (n == -2147483648)
	{
		min_int = itoa_negative(2147483647);
		if (!min_int)
			return (NULL);
		min_int[10] = '8';
		return (min_int);
	}
	if (n == 0)
	{
		nb = (char *)malloc(2 * sizeof(char));
		if (!nb)
			return (NULL);
		nb[0] = '0';
		nb[1] = '\0';
		return (nb);
	}
	return (NULL);
}

/* #include <stdio.h>

int main(void)
{
	int n = 0;
	char *nb = ft_itoa(n);
	printf("%s\n", nb);
	free(nb);
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *nb = ft_itoa(ft_atoi(av[1]));
		printf("%s\n", nb);
		if (!nb)
			return (0);
		free(nb);
		return (0);
	}
	return (0);
} */