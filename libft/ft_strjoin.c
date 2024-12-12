/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:06:17 by akloster          #+#    #+#             */
/*   Updated: 2023/11/08 13:53:29 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	putstr(char *str, char const *s, size_t i, size_t j)
{
	while (s[i] != '\0')
	{
		str[i + j] = s[i];
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	putstr(str, s2, 0, putstr(str, s1, 0, 0));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (str);
}

/* #include <stdio.h>

int main(void)
{
	char s1[] = "Hello ";
	char s2[] = "World!";
	char *str = ft_strjoin(s1, s2);
	printf("%s$\n", str);
	if (str)
		free(str);
	return (0);
} */