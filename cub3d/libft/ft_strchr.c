/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:51:48 by akloster          #+#    #+#             */
/*   Updated: 2023/11/06 14:21:50 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	find;
	char	*ptr;

	i = 0;
	find = (char) c;
	ptr = (char *) s;
	while (s[i] != find && s[i] != '\0')
		++i;
	if (s[i] == find)
		return (ptr + i);
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "";
	char find = '\0';
	printf("%s\n", ft_strchr(&str[0], find));
	printf("%s\n", strchr(&str[0], find));
} */