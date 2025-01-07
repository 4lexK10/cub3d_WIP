/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:21 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:48:21 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		++src;
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
	int src[] = {41, 42, 43};
	int dest[] = {0, 0, 0};
	int lim = 3;
	ft_memcpy(dest, src, lim);   
	for (int i = 0; i < lim; ++i)
		printf("%d ", dest[i]);
	printf("\n");
}

int main()
{
	char src[] = "Hello World";
	char const *s = NULL;
	char *d = &src[0];
	size_t lim = 12;
	printf("   ft_memcpy = %s\n", ft_memcpy(d, s, lim));
} */