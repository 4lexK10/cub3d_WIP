/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:37:46 by akloster          #+#    #+#             */
/*   Updated: 2023/10/27 18:37:44 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main(void)
{
	char c = 'A';
	printf("before = %c\nafter = %c\n", c, ft_toupper(c));
	printf("\nbefore = %c\nafter = %c\n", c, toupper(c));
	return (0);
}

int main()
{
	int i;
	char c;
	i = 0;
	printf("\n-------\n");
    while (i <= 128)
    {
        c = toupper(i);
        write(1, &c, 1);
        i++;
    }
	printf("\n-------\n");
	i = 0;
    while (i <= 128)
    {
        c = ft_toupper(i);
        write(1, &c, 1);
        i++;
    }
	printf("\n");
	return (0);
} */