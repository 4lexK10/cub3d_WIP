/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:36:10 by akloster          #+#    #+#             */
/*   Updated: 2023/11/06 19:20:47 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putstr(size_t pre, size_t post, char const *s1)
{
	size_t	i;
	char	*str;

	if (s1[0] == '\0' || pre >= ft_strlen(s1))
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	str = (char *)malloc((post - pre + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i <= post - pre)
	{
		str[i] = s1[pre + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static char	*trimer(char const *s1, char const *set, size_t pre, size_t post)
{
	size_t	i;

	i = 0;
	if (s1 && !set)
		return (putstr(pre, post, s1));
	while (set[i] != '\0')
	{
		if (set[i] == s1[pre])
		{
			i = 0;
			++pre;
		}
		if (set[i] == s1[post])
		{
			i = 0;
			--post;
		}
		if (set[i] != s1[pre] && set[i] != s1[post])
			++i;
	}
	return (putstr(pre, post, s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (NULL);
	return (trimer(s1, set, 0, ft_strlen(s1) - 1));
}

/* #include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *str = ft_strtrim(av[1], av[2]);
		printf("%s$\n", str);
		if (!str)
			return (0);
		free(str);
	}
	return (0);
}

int main (void)
{
	printf("%s$\n", ft_strtrim("", ""));
	return (0);
} */