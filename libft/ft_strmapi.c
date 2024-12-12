/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:17:00 by akloster          #+#    #+#             */
/*   Updated: 2023/10/23 15:23:37 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*s_new;

	if (!f || !s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	s_new = (char *)malloc((size + 1) * sizeof(char));
	if (!s_new)
		return (NULL);
	while (s[i] != '\0')
	{
		s_new[i] = f(i, s[i]);
		++i;
	}
	s_new[i] = '\0';
	return (s_new);
}

/* #include <stdio.h>

char	to_e(unsigned int i, char c)
{
	if (i % 2 == 1)
		return('e');
	return (c);
}

int main(void)
{
	char str[] = "HHHHHHHHHH";
	printf("before =%s$\n", str);
	printf("after  =%s$\n", ft_strmapi(str, to_e));
	return (0);
} */