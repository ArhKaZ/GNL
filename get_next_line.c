/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:14:43 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/30 18:04:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_save(char *stat_char)
{
	char	*temp;

	temp = ft_strdup(stat_char);
	free(stat_char);
	if (ft_strchr(temp, '\n'))
		stat_char = ft_strdup(ft_strchr(temp, '\n') + 1);
	free(temp);
	return (stat_char);
}

char	*ft_choice(char *buff, char *str_return)
{
	char	*temp;

	if (str_return == NULL)
		str_return = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(str_return, buff);
		free(str_return);
		str_return = ft_strdup(temp);
		free(temp);
	}
	free(buff);
	return (str_return);
}

char	*ft_get_line(int fd, char *stat_char)
{
	char	buff[BUFFER_SIZE + 1];
	char	*cpybuff;
	int		ret;

	ret = 1;
	while (ret != 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0)
			return (NULL);
		cpybuff = ft_strdup(buff);
		stat_char = ft_choice(cpybuff, stat_char);
		if (ret < BUFFER_SIZE)
			break;
		if (ft_strchr(stat_char, '\n'))
			break;
	}
	return (stat_char);
}

char	*ft_line(char *temp)
{
	char	*str_return;
	int		max;

	max = 0;
	while (temp[max] && temp[max] != '\n')
		max++;
	if (ft_strchr(temp, '\n'))
	{
		str_return = malloc(sizeof(char) * (max + 2));
		str_return[max] = '\n';
		str_return[max + 1] = '\0';
	}
	else
	{
		str_return = malloc(sizeof(char) * (max + 1));
		str_return[max] = '\0';
	}
	while (max > 0)
	{
		str_return[max - 1] = temp[max - 1];
		max--;
	}
	return (str_return);
}

char	*get_next_line(int fd)
{
	static char	*stat_char;
	char		*final_str;

	final_str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat_char = ft_get_line(fd, stat_char);
	if (stat_char == NULL)
	{
		free(stat_char);
		return (NULL);
	}
	final_str = ft_line(stat_char);
	if (ft_strchr(stat_char, '\n'))
		stat_char = ft_save(stat_char);
	return (final_str);
}

#include <fcntl.h>
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd;
		//char *path = "bible.txt";
		fd = open(argv[1], O_RDONLY);
		char *line;
		line = get_next_line(fd);
		printf("[%s]", line);
		free(line);
		line = get_next_line(fd);
		printf("[%s]", line);
		free(line);
		line = get_next_line(fd);
		printf("[%s]", line);
		free(line);
		close(fd);
	}
	return (0);
}
