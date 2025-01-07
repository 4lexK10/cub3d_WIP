/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:34:07 by akloster          #+#    #+#             */
/*   Updated: 2023/11/08 16:20:50 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (dstsize < len_dst)
		len_dst = dstsize;
	while (src[i] != '\0' && i + len_dst < dstsize - 1 && dstsize != 0)
	{
		dst[len_dst + i] = src[i];
		++i;
	}
	if (dstsize > len_dst)
		dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char dst[100] = "Hello ";
	char dst0[100] = "Hello ";
	char src[] = "World!";
	printf("%zu %s$\n", ft_strlcat(0, src, 0), dst);
	printf("%zu $\n", strlcat(0, src, 0), dst0);
} */