/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:32:20 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/26 21:04:13 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_msg.h"
#include "libft.h"
#include <fcntl.h>

static char	**ft_get_str_to_map_by_split(char *ber_file_str)
{
	char	**map;

	map = ft_split((const char *)ber_file_str, '\n');
	return (map);
}

static char	*ft_get_berfile_to_str(char *mappath)
{
	int		fd;
	char	*ber_file_str;

	fd = open((const char *)mappath, O_RDONLY);
	if (fd < 0)
		ft_myexit(NULL, OPEN_MAP_FAIL, NULL, EXIT_FAILURE);
	ber_file_str = ft_get_file_to_str(fd);
	return (ber_file_str);
}

void	ft_init_mapdata(t_gmobj *gm, char *mappath)
{
	char	*ber_file_str;
	char	**map;

	ber_file_str = ft_get_berfile_to_str(mappath);
	if (ber_file_str == NULL)
		ft_myexit(NULL, READ_MAP_FAIL, NULL, EXIT_FAILURE);
	if (ft_check_map_char(ber_file_str))
	{
		free(ber_file_str);
		ft_myexit(NULL, INVALID_MAP_CHAR, NULL, EXIT_FAILURE);
	}
	map = ft_get_str_to_map_by_split(ber_file_str);
	free(ber_file_str);
	if (map == NULL)
		ft_myexit(NULL, SPLIT_MAP_FAIL, NULL, EXIT_FAILURE);
	if (ft_check_map_rect(gm, map))
	{
		ft_cleanmap(map);
		ft_myexit(NULL, INVALID_MAP_RECT, NULL, EXIT_FAILURE);
	}
	gm->map = map;
}
