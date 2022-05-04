/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:28:02 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/26 21:21:14 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_msg.h"
#include "so_long_img_index.h"
#include "ft_printf.h"

int	ft_del_gmobj(t_gmobj *gm, int exitcd)
{
	int		i;
	char	**save;

	i = 0;
	while (i <= IMG_CNT_MAX)
	{
		if (gm->img[i] != NULL)
			mlx_destroy_image(gm->mlx, gm->img[i]);
		i++;
	}
	if (gm->mlx != NULL || gm->win != NULL)
		mlx_destroy_window(gm->mlx, gm->win);
	if (gm->mlx != NULL)
		mlx_destroy_display(gm->mlx);
	free(gm->mlx);
	save = gm->map;
	while (*(gm->map) != NULL)
		free(*(gm->map)++);
	free(save);
	exit(exitcd);
}

void	ft_myexit(t_gmobj *gm, char *msg, int (*f)(t_gmobj*, int), int exitcd)
{
	if (msg != NULL)
		(void)ft_printf("%s\n", msg);
	if (gm != NULL && f != NULL)
		f(gm, exitcd);
	exit(exitcd);
}

void	ft_cleanmap(char **map)
{
	char	**save;

	save = map;
	while (*map != NULL)
		free(*map++);
	free(save);
}

int	ft_mydosync(t_gmobj *gm)
{
	mlx_do_sync(gm->mlx);
	return (0);
}
