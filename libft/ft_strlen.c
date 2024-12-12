/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:48 by akloster          #+#    #+#             */
/*   Updated: 2023/10/17 16:48:48 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	printf("size of array = %zu\n", ft_strlen(NULL));
	printf("size of array = %zu\n", strlen(NULL));
} */