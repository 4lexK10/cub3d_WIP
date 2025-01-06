/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:41 by akloster          #+#    #+#             */
/*   Updated: 2025/01/04 21:09:22 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_read(int fd, char **str)
{
	char	*buf;
	char	*temp;
	int		cnt;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	if (*str && finder(*str) >= 0)
		return (free(buf), -5);
	cnt = read(fd, buf, BUFFER_SIZE);
	if (cnt <= 0)
		return (free(buf), cnt);
	if (cnt > 0)
		buf[cnt] = '\0';
	if (!*str)
		temp = ft_mod_strdup(buf, -1);
	else
		temp = ft_mod_strjoin(*str, buf);
	clear(str, &buf);
	if (!temp)
		return (-1);
	*str = temp;
	return (cnt);
}

static char	*special_case(char **str)
{
	char	*res;
	char	*temp;

	temp = ft_mod_strdup((*str) + 1, -1);
	if (!temp)
		return (clear(str, NULL));
	if (*temp == '\0')
		clear(&temp, NULL);
	res = ft_mod_strdup("\n", -1);
	if (!res)
		return (clear(str, &temp));
	clear(str, NULL);
	*str = temp;
	return (res);
}

static char	*cleaner(char **str, char *nl)
{
	char	*temp;
	char	*res;

	if (!nl)
	{
		res = ft_mod_strdup(*str, -1);
		clear(str, NULL);
		if (!res)
			return (NULL);
		return (res);
	}
	if (*nl == **str)
		return (special_case(str));
	else
		temp = ft_mod_strdup(++nl, -1);
	if (!temp)
		return (clear(str, NULL));
	res = ft_mod_strdup(*str, finder(*str));
	if (!res)
		return (clear(str, &temp));
	clear(str, NULL);
	if (*temp == '\0')
		clear(&temp, NULL);
	*str = temp;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*nl;
	int			cnt;

	if (BUFFER_SIZE >= INT_MAX || fd < 0 || BUFFER_SIZE < 1) 
		return (NULL);
	cnt = BUFFER_SIZE;
	if (!str)
		cnt = get_read(fd, &str);
	if (!str || cnt <= 0)
		return (clear(&str, NULL));
	while (cnt > 0 && cnt == BUFFER_SIZE)
		cnt = get_read(fd, &str);
	if (cnt == -1)
		return (clear(&str, NULL));
	nl = str + finder(str);
	if (finder(str) < 0)
		nl = NULL;
	return (cleaner(&str, nl));
}

/* #include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *str;

	fd = open("big", O_RDONLY);
	while((str = get_next_line(fd)))
		printf("%s", str);
} */
