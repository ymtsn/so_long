/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:41:46 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 11:22:38 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long_img_index_bonus.h"
#include "so_long_drawing_bonus.h"
#define GO_AHEAD 0
#define CANNOT_GO 1

static int	ft_check_enemy_forward(t_gmobj *gm, int x, int y)
{
	int	item;

	item = *(*(gm->map + (gm->eny.y + y)) + gm->eny.x + x);
	if (item != SPACE)
		return (CANNOT_GO);
	return (GO_AHEAD);
}

static void	ft_enemy_move(t_gmobj *gm, int x, int y, int d)
{
	if (ft_check_enemy_forward(gm, x, y))
		return ;
	*(*(gm->map + gm->eny.y) + gm->eny.x) = SPACE;
	*(*(gm->map + gm->eny.y + y) + gm->eny.x + x) = ENEMY;
	gm->eny.x += x;
	gm->eny.y += y;
	gm->eny.d = d;
}

void	ft_enemy_move_hndl(t_gmobj *gm)
{
	int	ply_diff_x;
	int	ply_diff_y;
	int	randomize;

	if (gm->ply.x < gm->eny.x)
		ply_diff_x = -1;
	else
		ply_diff_x = 1;
	if (gm->ply.y < gm->eny.y)
		ply_diff_y = -1;
	else
		ply_diff_y = 1;
	randomize = rand() % 10;
	if (1 < randomize)
		return ;
	if (randomize == 0 && ply_diff_x == -1)
		ft_enemy_move(gm, ply_diff_x, 0, EN_L);
	else if (randomize == 0 && ply_diff_x == 1)
		ft_enemy_move(gm, ply_diff_x, 0, EN_R);
	else if (randomize == 1 && ply_diff_y == -1)
		ft_enemy_move(gm, 0, ply_diff_y, EN_B);
	else if (randomize == 1 && ply_diff_y == 1)
		ft_enemy_move(gm, 0, ply_diff_y, EN_F);
}
