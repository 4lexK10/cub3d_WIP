/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:14:20 by akloster          #+#    #+#             */
/*   Updated: 2023/11/01 13:45:51 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		++i;
	str = (char *)malloc((1 + i) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
/* 
#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[] = "Hello World!";
	char *s = str;
	char *ptr = ft_strdup(s);
	char *ptr0 = strdup(s);
	printf("ft_strdup = %s\n" , ptr);
	printf("  strdup = %s\n", ptr0);
	free(ptr);
	free(ptr0);
	return (0);
} */