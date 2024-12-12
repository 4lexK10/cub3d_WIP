/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:12:02 by akloster          #+#    #+#             */
/*   Updated: 2023/11/06 13:29:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert_nb(int nb, int fd)
{
	int		i;
	char	rev_nb[10];
	char	c;

	i = 0;
	while (nb > 0)
	{
		rev_nb[i] = '0' + (nb % 10);
		nb /= 10;
		++i;
	}
	while (i > 0)
	{
		c = rev_nb[i - 1];
		write(fd, &c, 1);
		--i;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0 && n >= -2147483647)
	{
		write(fd, "-", 1);
		n *= -1;
		convert_nb(n, fd);
	}
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else if (n == 0)
		write(fd, "0", 1);
	else
		convert_nb(n, fd);
}
