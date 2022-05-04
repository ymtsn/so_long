/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:28:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/21 17:20:36 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define ERROR -1
#define CONTINUE 1
#define NOREAD 2
#define BUFFER_SIZE 1024

static int	ft_join_stck_rd(char **stock, char **readbuf, int INFO)
{
	char	*buf;
	char	*temp;
	size_t	len;

	len = ft_strlen(*readbuf) + ft_strlen(*stock);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL || INFO == ERROR || len == 0)
	{
		free(buf);
		free(*stock);
		free(*readbuf);
		return (ERROR);
	}
	temp = *stock;
	while (*stock != NULL && **stock)
		*buf++ = *(*stock)++;
	free(temp);
	temp = *readbuf;
	while (*readbuf != NULL && **readbuf)
		*buf++ = *(*readbuf)++;
	free(temp);
	*buf = '\0';
	buf -= len;
	*stock = buf;
	return (INFO);
}

static int	ft_make_readbuf(int fd, char **readbuf)
{
	ssize_t	readlen;

	*readbuf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (*readbuf == NULL)
		return (ERROR);
	readlen = read(fd, *readbuf, BUFFER_SIZE);
	if (readlen < 0 || readlen == 0)
	{
		free(*readbuf);
		*readbuf = NULL;
	}
	if (readlen < 0)
		return (ERROR);
	if (readlen == 0)
		return (NOREAD);
	*(*(readbuf) + readlen) = '\0';
	return (CONTINUE);
}

char	*ft_get_file_to_str(int fd)
{
	static char	*stock;
	static int	INFO;
	char		*readbuf;

	if (fd < 0)
		return (NULL);
	while (INFO != ERROR)
	{
		INFO = ft_make_readbuf(fd, &readbuf);
		INFO = ft_join_stck_rd(&stock, &readbuf, INFO);
		if (INFO == NOREAD)
			return (stock);
	}
	return (NULL);
}
