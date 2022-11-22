/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:03:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 15:45:30 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char	*ft_empty(char *str, char buf)
{

}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	int		nblu;
	char	*str_to_return;

	nblu = read(fd, &buf, BUFFER_SIZE);
	
}
