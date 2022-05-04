/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:20:37 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/28 21:15:14 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_msg.h"
#include "libft.h"

static int	ft_check_filename_is_dot(char *filename)
{
	char	*find;

	find = ft_strrchr(filename, '/');
	if (find != NULL)
		return (*(find + 1) == '.');
	return (*filename == '.');
}

static int	ft_check_extention(char *filename, size_t len)
{
	return (ft_strncmp(".ber", (filename + (len - 4)), 4) != 0);
}

static int	ft_check_minimum(size_t len)
{
	return (len < 5);
}

void	ft_check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_check_minimum(len))
		ft_myexit(NULL, INVALID_FILE_FORM, NULL, EXIT_FAILURE);
	if (ft_check_extention(filename, len))
		ft_myexit(NULL, INVALID_FILE_FORM, NULL, EXIT_FAILURE);
	if (ft_check_filename_is_dot(filename))
		ft_myexit(NULL, INVALID_FILE_FORM, NULL, EXIT_FAILURE);
}
