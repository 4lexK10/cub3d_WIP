/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:10:48 by akloster          #+#    #+#             */
/*   Updated: 2023/11/06 19:36:53 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_split(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] == c && s[i] != '\0')
	{
		if (s[i + 1] == '\0')
			return (0);
		++i;
	}
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (len);
		++len;
		++i;
	}
	return (len);
}

static char	*make_str(size_t len)
{
	char	*str;

	if (len == 0)
		return (NULL);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	return (str);
}

static size_t	count_split(char const *s, char c)
{
	size_t	split;
	size_t	i;

	i = 0;
	split = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			++i;
		while (s[i] != c && s[i] != '\0')
			++i;
		++split;
		if (s[i] == '\0' && s[i - 1] == c)
			--split;
	}
	return (split);
}

static char	**fill_split(char const *s, char c, char **arr_str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k] != '\0' && i < count_split(s, c))
	{
		while (s[k] == c && s[k] != '\0')
			++k;
		arr_str[i] = make_str(strlen_split(s, c, k));
		if (!arr_str[i])
			return (NULL);
		while (s[k] != c && s[k] != '\0')
			arr_str[i][j++] = s[k++];
		arr_str[i++][j] = '\0';
		j = 0;
	}
	arr_str[i] = NULL;
	return (arr_str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_str;
	char	**arr_str2;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = count_split(s, c);
	arr_str = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr_str)
		return (NULL);
	arr_str2 = fill_split(s, c, arr_str);
	if (!arr_str2)
	{
		while (arr_str[i] != NULL)
			free(arr_str[i++]);
		free(arr_str);
		return (NULL);
	}
	return (arr_str2);
}

/* #include <stdio.h>

int main(int ac, char ** av)
{
	if (ac == 3)
	{
		size_t i = 0;
		char **arr_str = ft_split(av[1], *av[2]);
		while (arr_str[i] != NULL)
			printf("%s$\n", arr_str[i++]);
		if (arr_str)
			free(arr_str);
	}
	return (0);
} */