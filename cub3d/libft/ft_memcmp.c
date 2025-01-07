/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:00:23 by akloster          #+#    #+#             */
/*   Updated: 2023/11/01 13:47:06 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && i < n - 1)
		++i;
	return (ptr1[i] - ptr2[i]);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "Hello\0";
	char str2[] = "Hello\200";
	size_t lim = 6;
	printf("ft_memcmp = %d\n   memcmp = %d\n", 
	ft_memcmp(str1, str2, lim), memcmp(str1, str2, lim));
} */