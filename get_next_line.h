/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayprokop <ayprokop@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:38:18 by ayprokop          #+#    #+#             */
/*   Updated: 2024/02/29 12:58:49 by ayprokop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
// open()
# include <unistd.h>
// read() 
# include <stdlib.h>
// malloc()

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_realloc(void *ptr, size_t size);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);

#endif