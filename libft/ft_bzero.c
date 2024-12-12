/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:34 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:34 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		--n;
		++s;
	}
}

/* #include <strings.h>
#include <stdio.h>

int main()
{
	// char str1[] = "Hello world!";
	char str2[] = "Hello world!";

	// bzero(str1, 3);
	ft_bzero(str2, 0);
	// printf("ft_bzero = %s\n", str1);
	printf("bzero    = %s\n", str2);
} */