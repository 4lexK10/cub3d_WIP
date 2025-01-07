/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:13:03 by akloster          #+#    #+#             */
/*   Updated: 2023/11/01 12:42:11 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char		*dst;
	char const	*s;

	dst = (char *) dest;
	s = (char const *) src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dst == src)
		return (dest);
	if (dst < s)
	{
		while (n-- > 0)
		{
			*dst = *s;
			++dst;
			++s;
		}
		return (dest);
	}
	if (dst > s)
		while (n-- > 0)
			*(dst + n) = *(s + n);
	return (dest);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char s0[] = "Hello World!";
	char *test = NULL;
	char *dst0 = &s0[0] + 1;
	size_t lim = 10;
	printf("memmove = %s$\n", memmove(dst0, &s0[0], lim));
	return (0);
} */