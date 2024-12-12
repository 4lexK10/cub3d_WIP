/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:36:16 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 13:51:08 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	find;
	char	*ptr_0;
	char	*ptr;

	i = 0;
	find = (char) c;
	ptr_0 = (char *) s;
	ptr = (char *) s;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			ptr = ptr_0 + i;
		++i;
	}
	if (find == '\0')
		return (ptr + i);
	if (*ptr == find)
		return (ptr);
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Hello World!";
	char find = '!';
	printf("%s\n", ft_strrchr(&str[0], find));
	printf("%s\n", strrchr(&str[0], find));
} */