/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:30 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:48:30 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)dest = c;
		++dest;
		++i;
	}
	dest -= i;
	return (dest); 
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char str_control[] = "Hello World";
	// char str_test[] = "Hello World";
	memset(str_control, 49, 0);
	// ft_memset(str_test, 49, 0);
	// printf("control = %s\ntest    = %s\n", str_control, str_test);
	// printf("test    = %s\n", str_test);
	printf("control = %s\n", str_control);
} */