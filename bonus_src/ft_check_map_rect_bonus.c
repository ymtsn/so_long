/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_rect_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:10:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 10:49:14 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
#define INVALID_RECT 1
#define VALID_RECT 0

static int	ft_is_line_same_len(char *map_line, size_t first_line_len)
{
	return (first_line_len != ft_strlen(map_line));
}

static int	ft_is_line_start_end_wall(char *map_line, size_t line_len)
{
	if (*map_line != '1')
		return (1);
	if (*(map_line + (line_len - 1)) != '1')
		return (1);
	return (0);
}

static	int	ft_is_line_all_wall(char *map_line)
{
	size_t	x;

	x = 0;
	while (*(map_line + x) != '\0')
	{
		if (*(map_line + x) != '1')
			return (1);
		x++;
	}
	return (0);
}

int	ft_check_map_rect(t_gmobj *gm, char **map)
{
	size_t	y;
	size_t	first_line_len;

	y = 0;
	first_line_len = ft_strlen(*(map + y++));
	if (ft_is_line_all_wall(*map))
		return (INVALID_RECT);
	while (*(map + y) != NULL)
	{
		if (ft_is_line_same_len(*(map + y), first_line_len))
			return (INVALID_RECT);
		if (ft_is_line_start_end_wall(*(map + y), first_line_len))
			return (INVALID_RECT);
		y++;
	}
	if (ft_is_line_all_wall(*(map + (y - 1))))
		return (INVALID_RECT);
	gm->map_x_len = first_line_len;
	gm->map_y_len = y;
	return (VALID_RECT);
}
