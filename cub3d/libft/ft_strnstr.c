/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:15:52 by akloster          #+#    #+#             */
/*   Updated: 2023/11/08 16:30:35 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*find;

	if (needle && !haystack && len == 0)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *) haystack;
	find = (char *) needle;
	if (find[0] == '\0' || !needle)
		return (str);
	while (i <= len && str[i] != '\0')
	{
		while (str[i + j] == find[j] && i + j <= len)
		{
			++j;
			if (find[j] == '\0' && i + j <= len)
				return (str + i);
		}
		j = 0;
		++i;
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>

int main(void)
{
	char haystack[] = "oouakoooo";
	char needle[] = "a";
	char *h = haystack;
	char *n = needle;
	size_t lim = 2;
	printf("   strnsrt = %s\n", strnstr(0, n, lim));
	printf("ft_strnstr = %s\n", ft_strnstr(0, n, lim));
} */