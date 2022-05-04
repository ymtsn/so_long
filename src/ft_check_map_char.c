/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:08:29 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/26 21:01:44 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define VALID_MAP_CHAR 0
#define INVALID_MAP_CHAR 1

static int	ft_invalid_char(char *map)
{
	size_t	i;

	i = 0;
	while (*(map + i) && (ft_strchr("01CPE\n", *(map + i)) != NULL))
		i++;
	return (i != ft_strlen(map));
}

static int	ft_no_exit_or_no_collect(char *map)
{
	return (ft_strchr(map, 'E') == NULL || ft_strchr(map, 'C') == NULL);
}

static int	ft_no_plyer_or_double_plyer(char *map)
{
	char	*ply;

	ply = ft_strchr(map, 'P');
	return ((ply == NULL) || ply != ft_strrchr(map, 'P'));
}

static int	ft_invalid_newline(char *map)
{
	return (*map == '\n' || (ft_strnstr(map, "\n\n", ft_strlen(map)) != NULL));
}

int	ft_check_map_char(char *map)
{
	int	(*check_map_func[4])(char *);
	int	i;

	check_map_func[0] = ft_invalid_newline;
	check_map_func[1] = ft_no_plyer_or_double_plyer;
	check_map_func[2] = ft_no_exit_or_no_collect;
	check_map_func[3] = ft_invalid_char;
	i = 0;
	while (i < 4)
	{
		if (check_map_func[i](map))
			return (INVALID_MAP_CHAR);
		i++;
	}
	return (VALID_MAP_CHAR);
}
