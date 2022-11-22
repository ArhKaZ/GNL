/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:03:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 16:25:23 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// int	ft_size_of_lign(int fd)
// {
// 	int count;
// 	char c;

// 	count = 0;
// 	while (read(fd, &c, 1))
// 	{
// 		if (c == '\n')
// 			return (count);
// 		count++;
// 	}
// 	return (0);
// }
int ft_strlen(char const *s)
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

void	ft_empty(char *buf, char *str)
{
	char *temp;

	printf("%s", ft_strdup(buf));
	if (str == NULL)
		str = ft_strdup(buf);
	else
	{
		temp = ft_strdup(buf);
		str = ft_strjoin(str, temp);
		free(temp);
	}
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	int		nblu;
	char	*str_to_return;

	str_to_return = NULL;
	nblu = read(fd, &buf, BUFFER_SIZE);
	ft_empty(buf, str_to_return);
	return (str_to_return);
}


#include <fcntl.h>
int main()
{
	int fd;

	fd = open("bible.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
