/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:44:17 by atu               #+#    #+#             */
/*   Updated: 2023/12/22 20:57:51 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	try_read(char *buffer, char **line, int fd)
{
	int			red;

	red = 0;
	if (*buffer == '\0')
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red <= 0)
		{
			buffer[0] = '\0';
			if (red == 0 && **line != '\0')
				return (0);
			free(*line);
			return (-1);
		}
		buffer[red] = '\0';
	}
	return (1);
}

int	try_get_line(char *buffer, char **line)
{
	char		*temp;
	char		*eol;

	eol = ft_strchr(buffer, '\n');
	if (eol != NULL)
	{
		temp = *line;
		*line = ft_strnjoin(*line, buffer, eol - buffer + 1);
		free(temp);
		ft_memmove(buffer, eol + 1, BUFFER_SIZE - (eol - buffer));
		return (1);
	}
	else
	{
		temp = *line;
		*line = ft_strnjoin(*line, buffer, ft_strlen(buffer));
		free(temp);
		buffer[0] = '\0';
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			red;

	if (fd < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line = ft_calloc(1, 1);
	if (line != NULL)
	{
		while (1)
		{
			red = try_read(buffer, &line, fd);
			if (red == -1)
				return (NULL);
			if (red == 0)
				return (line);
			if (red == 1)
				if (try_get_line(buffer, &line))
					return (line);
		}
	}
	return (line);
}
