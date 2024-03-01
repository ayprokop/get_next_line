/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayprokop <ayprokop@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:40:00 by ayprokop          #+#    #+#             */
/*   Updated: 2024/03/01 10:21:23 by ayprokop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_build_backup(int fd, char *backup)
{
	char	buf[BUFFER_SIZE];
	size_t	done;
	size_t	size;
	
	done = 0;
	size = BUFFER_SIZE;
	done = read(fd, buf, BUFFER_SIZE - 1);
	if (done == -1)
		return (NULL);
	buf[done] = '\0';
	backup = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	backup = ft_strjoin(backup, buf);
	while ((done = read(fd, buf, BUFFER_SIZE - 1)) > 0)
	{
		// printf("++done: %lu\n", done);
		buf[done] = '\0';
		// printf("--buf: %s\n", buf);
		size += done;
		backup = (char *)ft_realloc(backup, size);
		backup = ft_strjoin(backup, buf);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
		// printf("###backup: %s\n", backup);
		// printf("--done: %lu\n", done);
		if (done == -1)
			return (NULL);
	}
	return (backup);
}

static char	*ft_put_line(char *line)
{
	char	*str;
	int		i;
	int		count;
	
	count = 0;
	while (line[count] != '\n')
		count++;
	printf("##count: %d\n", count);
	str = (char *)malloc(sizeof(char) * (count + 2));
	i = 0;
	while (i < count)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	printf("++str: %s\n", str);
	return (str);
}

char	*ft_reduce_backup(char *tmp)
{
	printf("##**tmp: %s\n", tmp);
	char	*backup;
	int		linelen;
	int		size;
	int		i;

	linelen = 0;
	while (tmp[linelen] &&  tmp[linelen] != '\n')
		linelen++;
	size = ft_strlen(tmp) - (linelen + 1);
	backup = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (*tmp && i < size)
	{
		backup[i] = tmp[linelen + 1];
		i++;
		linelen++;
	} 
	backup[i] = '\0';
	printf("##**backup: %s\n", backup);
	
	
	
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*backup;

	static int	n = 1;
	printf("\n%d\n", n++);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = ft_build_backup(fd, backup);
	printf("++++tmp: %s\n", tmp);
	line = ft_put_line(tmp);
	printf("++++line: %s\n", line);
	backup = ft_reduce_backup(tmp);
	printf("++++backup: %s\n", backup);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;
	fd = open("file.txt", O_RDONLY);
	
	i = 0;
	while (i < 2)
	{
		printf("main: %s", get_next_line(fd));
		i++;
	}
	close(fd);
	
	return (0);
}