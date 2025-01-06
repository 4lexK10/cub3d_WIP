/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:51 by akloster          #+#    #+#             */
/*   Updated: 2025/01/04 21:08:14 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_mod_strjoin(char const *s1, char const *s2);
char	*ft_mod_strdup(char const *s1, int i_nl);
size_t	ft_mod_strlen(char const *s);
int		finder(char *s);
char	*clear(char **str, char **buf);

#endif
