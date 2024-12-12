/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:21:29 by akloster          #+#    #+#             */
/*   Updated: 2023/11/02 17:04:06 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*ptr;

	i = 0;
	find = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == find)
			return (ptr + i);
		++i;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char str[] = "Hello World!";
	char find = 'o';
	size_t lim = 19;
	printf("%s\n", ft_memchr(&str[0], find, lim));
	printf("%s\n", memchr(&str[0], find, lim));
}
int main()
{
	char s[] = {0, 1, 2, 3, 4, 5};
	printf("%s\n", ft_memchr(s, 2, 3));
	printf("%s\n", memchr(s, 2, 3));
} */