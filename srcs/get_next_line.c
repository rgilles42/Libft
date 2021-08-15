/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:07:57 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/02 15:08:02 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*get_line_buffered(char *str, int fd, int *nb_read)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	*nb_read = read(fd, buf, BUFFER_SIZE);
	while (*nb_read > 0)
	{
		buf[*nb_read] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

int	inject_line(char *str, char **line)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			return (1);
		}
		else
		{
			*line = ft_strdup(str);
			return (0);
		}
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

char	*rest_of_buffer(char *str)
{
	int		i;
	int		str_len;
	char	*tmp;

	i = 0;
	str_len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			tmp = str;
			str = ft_substr(str, i + 1, str_len - i - 1);
			free(tmp);
		}
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int			nb_read;
	static char	*str[2560];
	int			more_in_buffer;

	if (read(fd, str[fd], 0) || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	str[fd] = get_line_buffered(str[fd], fd, &nb_read);
	if (nb_read < 0)
		return (-1);
	more_in_buffer = inject_line(str[fd], line);
	if (more_in_buffer)
		str[fd] = rest_of_buffer(str[fd]);
	else
	{
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}
