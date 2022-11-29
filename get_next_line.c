/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:03:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/28 17:43:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
//============================================= FX FROM LIBFT =======================================
size_t ft_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size && nmenb >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * nmenb);
	if (!ptr)
		return (NULL);
	while (i < size * nmenb)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dup;

	dup = NULL;
	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = (char)s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = -1;
	sub = NULL;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (0);
	}
	else
	{
		if (ft_strlen(s + start) < len)
			sub = ft_calloc((ft_strlen(s + start) + 1), sizeof(char));
		else
			sub = ft_calloc((len + 1), sizeof(char));
		if (!sub)
			return (0);
		while (++i < len && s[start] && start + i < ft_strlen(s))
			sub[i] = s[start + i];
	}
	return (sub);
}
char	*ft_strcpy_endl(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = calloc(ft_strlen(s) + 2, sizeof(char));
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	free(s);
	return (str);
}
int	ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	if (ch == 0)
		return (i);
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

//=================================================================================================
// char	*save_buff(char *str)
// {
// 	static char	*stat_str;
// 	char		*str_return;
// 	int	max;

// 	max = 0;
// 	while (str[max] && str[max] != '\n')
// 	{
// 		str_return = str[max];
// 		max++;
// 	}
// 	if (str[max] == '\n')
// 		stat_str = ft_substr(str, max, ft_strlen(str) - max);
// 	return(str_return);
// }

char *save_follow_line(char *str)
{
	char	*str_return;
	static char	*stat_str;
	char	*temp;

	stat_str = cpy_buff()
	if (stat_str != NULL && ft_strchr(stat_str, '\n') >= 0)
	{
		str_return = ft_substr(stat_str, 0, ft_strchr(stat_str, '\n') + 1);
		temp = ft_substr(stat_str, ft_strchr(stat_str, '\n') + 1, ft_strlen(stat_str) - ft_strchr(stat_str, '\n'));
		free(stat_str);
		stat_str = ft_strdup(temp);
		free(temp);
		return (str_return);
	}
	else
	{
		str_return = ft_substr(stat_str, 0, ft_strchr(stat_str, '\n') + 1);
		temp = ft_substr(stat_str, ft_strchr(stat_str, '\n') + 1, ft_strlen(stat_str) - ft_strchr(stat_str, '\n'));
		free(stat_str);
		stat_str = ft_strdup(temp);
		free(temp);
		return (str_return);
	}
}

char	*cpy_buff(char *buff)
{
	char	*stat_str;
	char	*temp;

	if (stat_str == NULL)
			stat_str = ft_strdup(buff);
	else
	{
		temp = ft_strdup(stat_str);
		free(stat_str);
		stat_str = ft_strjoin(temp, buff);
		free(temp);
	}
	return (stat_str);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	static char	*stat_str;
	char		*str_return;
	int			ret;
	char		*temp;

	if (fd < 0 || read(fd, buff, 0) || BUFFER_SIZE < 0)
		return (NULL);
	str_return = NULL;
	if (stat_str != NULL && ft_strchr(stat_str, '\n') >= 0)
	{
		str_return = ft_substr(stat_str, 0, ft_strchr(stat_str, '\n') + 1);
		temp = ft_substr(stat_str, ft_strchr(stat_str, '\n') + 1, ft_strlen(stat_str) - ft_strchr(stat_str, '\n'));
		free(stat_str);
		stat_str = ft_strdup(temp);
		free(temp);
		return (str_return);
	}
	ft_bzero(buff, BUFFER_SIZE);
	ret = read(fd, buff, BUFFER_SIZE);
	while (!(ret ==  0))
	{
		if (stat_str == NULL)
			stat_str = ft_strdup(buff);
		else
		{
			temp = ft_strdup(stat_str);
			free(stat_str);
			stat_str = ft_strjoin(temp, buff);
			free(temp);
		}
		if (ft_strchr(stat_str, '\n') >= 0)
		{
			str_return = ft_substr(stat_str, 0, ft_strchr(stat_str, '\n') + 1);
			temp = ft_substr(stat_str, ft_strchr(stat_str, '\n') + 1, ft_strlen(stat_str) - ft_strchr(stat_str, '\n'));
			free(stat_str);
			stat_str = ft_strdup(temp);
			free(temp);
			return (str_return); 
		}
		ft_bzero(buff, BUFFER_SIZE);
		ret = read(fd, buff,BUFFER_SIZE);
	}
	return (NULL);
}

// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	char *path = "bible.txt";
// 	fd = open(path, O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s/%p", line, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
