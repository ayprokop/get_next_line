/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayprokop <ayprokop@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:40:00 by ayprokop          #+#    #+#             */
/*   Updated: 2024/03/20 07:56:34 by ayprokop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_build_line(int fd, char *buf, char *backup)
{
	char	*tmp;
	int		done;

	done = 1;
	while (done > 0)
	{
		done = read(fd, buf, BUFFER_SIZE);
		if (done == -1 || done == 0)
			break ;
		buf[done] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	free(buf);
	buf = NULL;
	return (backup);
}

char	*ft_build_backup(char *line)
{
	char	*backup;
	size_t	i;

	backup = NULL;
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	backup = ft_substr(line, i + 1, ft_strlen(line));
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_build_line(fd, buf, backup);
	if (!line)
		return (NULL);
	backup = ft_build_backup(line);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	fd = open("file.txt", O_RDONLY);
// 	int i = 0;
// 	while (i < 23)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
// // gcc -Werror -Wextra -Wall -D BUFFER_SIZE=43 *.c