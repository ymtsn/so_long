/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_axi_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:13:41 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 09:24:26 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_drawing.h"
#define DONT_MOVE_AXI 0
#define CAN_MOVE_AXI 1

static int	ft_check_wall_dist(t_gmobj *gm, int x, int y)
{
	size_t	jx;
	size_t	jy;

	jx = 0;
	jy = 0;
	if (x)
	{
		while (*(*(gm->map + gm->ply.y) + gm->ply.x + jx) != WALL)
			jx++;
		if (gm->ply.x - gm->ply.axi_x + jx < WIN_SIZE_MAX)
			return (DONT_MOVE_AXI);
	}
	if (y)
	{
		while (*(*(gm->map + gm->ply.y + jy) + gm->ply.x) != WALL)
			jy++;
		if (gm->ply.y - gm->ply.axi_y + jy < WIN_SIZE_MAX)
			return (DONT_MOVE_AXI);
	}
	return (CAN_MOVE_AXI);
}

static void	ft_change_axi_x_position(t_gmobj *gm, int x)
{
	if (x == 1)
	{
		if (ft_check_wall_dist(gm, 1, 0) == DONT_MOVE_AXI)
			return ;
		else
			if ((gm->ply.x - gm->ply.axi_x) > (WIN_SIZE_MAX / 2))
				gm->ply.axi_x += x;
	}
	if (x == -1)
	{
		if (gm->ply.axi_x == 0)
			return ;
		if ((x == -1) && ((gm->ply.x - gm->ply.axi_x) < (WIN_SIZE_MAX / 2)))
			gm->ply.axi_x += x;
	}
}

static void	ft_change_axi_y_position(t_gmobj *gm, int y)
{
	if (y == 1)
	{
		if (ft_check_wall_dist(gm, 0, 1) == DONT_MOVE_AXI)
			return ;
		else
			if ((gm->ply.y - gm->ply.axi_y) > (WIN_SIZE_MAX / 2))
				gm->ply.axi_y += y;
	}
	if (y == -1)
	{
		if (gm->ply.axi_y == 0)
			return ;
		if ((gm->ply.y - gm->ply.axi_y) < (WIN_SIZE_MAX / 2))
			gm->ply.axi_y += y;
	}
}

void	ft_change_axi_position(t_gmobj *gm, int x, int y)
{
	if (gm->map_x_len > WIN_SIZE_MAX)
		ft_change_axi_x_position(gm, x);
	if (gm->map_y_len > WIN_SIZE_MAX)
		ft_change_axi_y_position(gm, y);
}
