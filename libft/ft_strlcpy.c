/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:34:04 by akloster          #+#    #+#             */
/*   Updated: 2023/10/27 18:13:45 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t destsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		++len;
	while (src[i] != '\0' && i < destsize - 1 && destsize != 0)
	{
		dst[i] = src[i];
		++i;
	}
	if (destsize != 0)
		dst[i] = '\0';
	return (len);
}

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
	char	src[] = "Hello World!";
	char	*ptr_s = &src[0];
	char	*dst = (char *)malloc(13 * sizeof(char));
	int size_dst = ft_strlcpy(dst, ptr_s, 0);
	printf("ft_strlcpy: dst = %s size of src = %d\n", dst, size_dst);
	free(dst);
	char	*dst_0 = (char *)malloc(13 * sizeof(char));
	int size_dst0 = strlcpy(dst_0, ptr_s, 0);
	printf("   strlcpy: dst = %s size of src = %d\n", dst_0, size_dst0);
	free(dst_0);
	return (0);
}
int main(void)
{
	char	src[] = "Hello World!";
	char	*ptr_s = &src[0];
	char	*dst = (char *)malloc(3 * sizeof(char));
	int size_dst = strlcpy(dst, ptr_s, 1);
	printf("strlcpy: dst = %s size of src = %d\n", dst, size_dst);
	free(dst);
} */