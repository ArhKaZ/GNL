/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:03:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/29 16:34:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_save(char *buff)
{
	char *stat_char;

	stat_char = NULL;
	if (ft_strchr(buff, '\n'))
		stat_char = ft_strdup(ft_strchr(buff, '\n') + 1);
	return (stat_char);
}

char	*ft_get_line(int fd)
{
	char	*str_return;
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	str_return = NULL;
	ret = 1;
	ft_bzero(buff, BUFFER_SIZE + 1);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == 0)
		return NULL;
	str_return = ft_strdup(buff);
	while (ret != 0 && (!(ft_strchr(str_return, '\n'))))
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		str_return = ft_strjoin(str_return, buff);
		if (ret < BUFFER_SIZE)
			break;
	}
	return (str_return);
}

char	*ft_line(char *temp)
{
	char	*str_return;
	int		max;
	int		len;

	max = 0;
	while (temp[max] && temp[max] != '\n')
		max++;
	len = ft_strlen()
	str_return = malloc(sizeof(char) * (max + 2));
	while (i < max)
	{
		str_return[i] = temp[i];
		i++;
	}
	str_return[i] = '\n';
	str_return[i + 1] = '\0';
	free(temp);
	return (str_return);
}


char	*get_next_line(int fd)
{
	static char	*stat_char;
	char		*str_return;
	char		 *temp;

	temp = NULL;
	stat_char = NULL;
	str_return = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	stat_char = ft_get_line(fd);
	if (stat_char == NULL)
		return (NULL);
	if (ft_strchr(stat_char, '\n'))
	{
		str_return = ft_line(stat_char);
		stat_char = ft_save(stat_char);
	}
	return (str_return);
}

//==============================================================================
// char	*ft_save(char *buff)
// {
// 	char *stat_char;

// 	stat_char = NULL;
// 	if (ft_strchr(buff, '\n'))
// 		stat_char = ft_strdup(ft_strchr(buff, '\n') + 1);
// 	return (stat_char);
// }

// char	*ft_get_line(int fd)
// {
// 	char	*str_return;
// 	char	buff[BUFFER_SIZE + 1];
// 	int		ret;

// 	str_return = NULL;
// 	ret = 1;
// 	ft_bzero(buff, BUFFER_SIZE + 1);
// 	ret = read(fd, buff, BUFFER_SIZE);
// 	if (ret == 0)
// 		return NULL;
// 	str_return = ft_strdup(buff);
// 	while (ret != 0 && (!(ft_strchr(str_return, '\n'))))
// 	{
// 		ft_bzero(buff, BUFFER_SIZE + 1);
// 		ret = read(fd, buff, BUFFER_SIZE);
// 		if (ret == -1)
// 			return (NULL);
// 		str_return = ft_strjoin(str_return, buff);
// 		if (ret < BUFFER_SIZE)
// 			break;
// 	}
// 	return (str_return);
// }

// char	*ft_line(char *temp)
// {
// 	char	*str_return;
// 	int		max;
// 	int		i;

// 	max = 0;
// 	while (temp[max] && temp[max] != '\n')
// 		max++;
// 	i = 0;
// 	str_return = malloc(sizeof(char) * (max + 2));
// 	while (i < max)
// 	{
// 		str_return[i] = temp[i];
// 		i++;
// 	}
// 	str_return[i] = '\n';
// 	str_return[i + 1] = '\0';
// 	free(temp);
// 	return (str_return);
// }


// char	*get_next_line(int fd)
// {
// 	static char	*stat_char;
// 	char		*str_return;
// 	char		 *temp;

// 	temp = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
// 		return (NULL);
// 	if (stat_char != NULL)
// 	{
// 		temp = ft_strdup(stat_char);
// 		stat_char = ft_save(stat_char);
// 		str_return = ft_line(temp);
// 		if (ft_strchr(str_return, '\n'))
// 			return (str_return);
// 		str_return = ft_strjoin(str_return, ft_get_line(fd));
// 	}
// 	else
// 		str_return = ft_get_line(fd);
// 	if (str_return == NULL)
// 		return (NULL);
// 	if (ft_strchr(str_return, '\n'))
// 	{
// 		stat_char = ft_save(str_return);
// 		str_return = ft_line(str_return);
// 	}
// 	return (str_return);
// }

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
		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);
	}
	return (0);
}
