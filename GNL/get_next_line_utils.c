/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:47 by akloster          #+#    #+#             */
/*   Updated: 2025/01/07 09:56:06 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_mod_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_mod_strdup(char const *s, int i_nl)
{
	char	*str;
	int		i;

	i = 0;
	if (i_nl >= 0)
		i = i_nl + 1;
	else
		i = ft_mod_strlen(s);
	str = (char *)malloc((size_t)(1 + i) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (i_nl >= 0)
		while (++i <= i_nl)
			str[i] = s[i];
	else
		while (s[++i] != '\0')
			str[i] = s[i];
	str[i] = '\0';
	return (str);
}

int	finder(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\n')
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	if (s[i] == '\n')
		return (i);
	else
		return (-1);
}

char	*ft_mod_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_mod_strlen(s1) + ft_mod_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*clear(char **str, char **buf)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}
