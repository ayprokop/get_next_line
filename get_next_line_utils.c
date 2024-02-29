/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayprokop <ayprokop@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:42:31 by ayprokop          #+#    #+#             */
/*   Updated: 2024/02/29 12:58:03 by ayprokop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (len)
		{
			len--;
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
		}
	}
	else
	{
		while (len)
		{
			len--;
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*qtr;

	if (!ptr)
		return ((void *)malloc(size));
	qtr = (void *)malloc(size);
	if (!qtr)
		return (NULL);
	ft_memmove(qtr, ptr, size);
	free(ptr);
	return (qtr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strdup(const char *str)
{
	char		*copy;
	size_t		i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
