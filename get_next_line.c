/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:03:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/23 16:16:42 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
//============================================= FX FROM LIBFT =======================================
size_t ft_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
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

int	ft_strchr(const char *s, int c)
{
	int		i;
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
	return (0);
}

//=================================================================================================

// char	*read_fd(int fd)
// {
// 	char	buf[BUFFER_SIZE];
// 	char	*str;

// 	str = NULL;
// 	if (!(read(fd, &buf, BUFFER_SIZE)))
// 		return (0);
// 	else
// 		str = ft_strdup(buf);
// 	return (str);
// }

// char	*dup_or_join(char *dest, char *src)
// {
// 	if (dest == NULL)
// 		dest = ft_strdup(src);
// 	else
// 		dest = ft_strjoin(dest, src);
// 	free(src);
// 	return (dest);
// }



// int	is_endofline(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }




// char	*endline_or_not(char *buf)
// {
// 	static char	*save;
// 	char		*str;
// 	int			i;
// 	int			len;

// 	i = 0;
// 	if (!buf)
// 		return (NULL);
// 	if (save != NULL)
// 		buf = ft_strdup(save);
// 	while (buf[i])
// 	{
// 		if (buf[i] == '\n')
// 		{
// 			if (i > 0)
// 			{
// 				str = ft_substr(buf, 0, i - 1);
// 				len = ft_strlen(str);
// 				str[len] = '\n';
// 				str[len + i] = '\0';
// 				if (buf[i + 1] != '\0')
// 					save = ft_substr(buf, i, BUFFER_SIZE - i);
// 				return (str);
// 			}
// 			else
// 			{
// 				printf("cc");
// 				str = ft_substr("\n", 0, 1);
// 				return (str);
// 			}
// 		}
// 		i++;
// 	}
// 	str = ft_substr(buf, 0, BUFFER_SIZE);
// 	return (str);
// }


char	*get_next_line(int fd)
{
	char		*str;
	char		*cpbuf;
	char		*temp;
	char		buff[BUFFER_SIZE];
	static char	*save;
	int			pos_nl;

	str = NULL;
	read(fd, &buff, BUFFER_SIZE);
	//{
		// if (buf)
		// 	return (NULL);
		printf("%s", buff);
		cpbuf = ft_substr(buff, 0, BUFFER_SIZE);
		pos_nl = ft_strchr(cpbuf, '\n') + 1;
		if (pos_nl > 0)
		{
			temp = ft_substr(cpbuf, 0, pos_nl);
			if (str == NULL)
				str = ft_substr(temp, 0, ft_strlen(temp));
			else
				str = ft_strjoin(str, temp);
			save = ft_substr(cpbuf, pos_nl, ft_strlen(cpbuf));
			free(temp);
		}
		else
		{
			if (str == NULL)
				str = ft_substr(cpbuf, 0, BUFFER_SIZE);
			else
				str = ft_strjoin(str, cpbuf);
		}
		free(cpbuf);
	//}
	return (str);
}






#include <fcntl.h>
int main()
{
	int fd;
	char *path = "bible.txt";
	char *str;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	int i = 0;
	while (str[i])
	{
		printf("%d/", str[i]);
		i++;
	}
	str = get_next_line(fd);
	printf("\n");
	i = 0;
	while (str[i])
	{
		printf("%d/", str[i]);
		i++;
	}
	close(fd);
	return (0);
}
