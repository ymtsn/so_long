/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_parametor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:32:24 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 11:18:10 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_img_index.h"
#include "so_long_drawing.h"

static void	ft_map_collect_count(t_gmobj *gm)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (*(gm->map + y) != NULL)
	{
		while (*(*(gm->map + y) + x))
		{
			if (*(*(gm->map + y) + x) == 'C')
				gm->collec_cnt++;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	ft_get_camera_axi_on_window(t_gmobj *gm)
{
	if (gm->ply.x > WIN_SIZE_MAX)
		gm->ply.axi_x = gm->ply.x - WIN_SIZE_MAX + 1;
	else
		gm->ply.axi_x = 0;
	if (gm->ply.y > WIN_SIZE_MAX)
		gm->ply.axi_y = gm->ply.y - WIN_SIZE_MAX + 1;
	else
		gm->ply.axi_y = 0;
}

static void	ft_get_player_pos_on_map(t_gmobj *gm)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (*(gm->map + y) != NULL)
	{
		while (*(*(gm->map + y) + x) != '\0')
		{
			if (*(*(gm->map + y) + x) == PLAYER)
			{
				gm->ply.x = x;
				gm->ply.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_init_game_parametor(t_gmobj *gm)
{
	gm->ply.d = PL_F;
	ft_get_player_pos_on_map(gm);
	ft_get_camera_axi_on_window(gm);
	ft_map_collect_count(gm);
}
