/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:08:52 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/11/01 04:08:52 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_get_line_beforen(char *str)
{
	int		i;
	int		j;
	char	*line_with_n;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line_with_n = ft_calloc_gt((i + 2), 1);
	if (!line_with_n)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		line_with_n[j++] = str[i++];
	if (str[i] == '\n')
		line_with_n[j++] = '\n';
	return (line_with_n);
}

char	*ft_getline_after_n(char *str)
{
	int		i;
	int		j;
	char	*linesbr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	linesbr = ft_calloc_gt((ft_strlen_gnl(str) + 2), 1);
	if (!linesbr)
		return (NULL);
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i])
	{
		linesbr[j++] = str[i++];
	}
	free(str);
	return (linesbr);
}

char	*read_file(int fd, char *str)
{
	char	*buff;
	int		i;

	if (fd == -1)
		return (NULL);
	buff = ft_calloc_gt((BUFFER_SIZE + 2), sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_if_ifind__n(str) && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			if (str)
				free(str);
			free(buff);
			return (buff = NULL, NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin_gn(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
	{
		free(buff[fd]);
		return (buff[fd] = NULL, NULL);
	}
	line = ft_get_line_beforen(buff[fd]);
	if (!buff[fd] || !line)
	{
		free(buff[fd]);
		return (buff[fd] = NULL, NULL);
	}
	buff[fd] = ft_getline_after_n(buff[fd]);
	if (!buff[fd])
	{
		free(buff[fd]);
	}
	return (line);
}
