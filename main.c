/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:34 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/01 16:14:03 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd_1;
	int fd_2;
	//int fd_3;
	char *str;
	fd_1 = open("lines_around_10.txt", O_RDONLY);
	fd_2 = open("lines_around_10.txt", O_RDONLY);

	str = get_next_line(fd_1);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_1);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_2);
	printf("[[%s]]", str);
	str = get_next_line(fd_1);
	printf("[[%s]]", str);
	str = get_next_line(fd_1);
	printf("[[%s]]", str);
	str = get_next_line(fd_1);
	printf("[[%s]]", str);
	free(str);
	//char *str = "s";
	// while (str != NULL)
	// {
	// 	str = get_next_line(fd_1);
	// 	printf("%s", str);
	// 	free(str);
	// }
	return 0;
}