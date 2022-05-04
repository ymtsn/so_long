/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyevent_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:13:41 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 11:31:24 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long_msg_bonus.h"
#include "so_long_drawing_bonus.h"
#include "so_long_img_index_bonus.h"
#include "so_long_keysym_bonus.h"
#include "ft_printf.h"
#define GO_AHEAD 0
#define CANNOT_GO 1

static int	ft_check_player_forward(t_gmobj *gm, int x, int y)
{
	int	item;

	item = *(*(gm->map + (gm->ply.y + y)) + gm->ply.x + x);
	if (item == SPACE)
		return (GO_AHEAD);
	else if (item == COLLEC)
	{
		gm->collec_cnt--;
		return (GO_AHEAD);
	}
	if (item == EXIT && gm->flg_exit == 1)
		ft_myexit(gm, EXIT_MAP, ft_del_gmobj, EXIT_SUCCESS);
	return (CANNOT_GO);
}

static void	ft_keyevent(t_gmobj *gm, int x, int y, int d)
{
	if (ft_check_player_forward(gm, x, y) == CANNOT_GO)
		return ;
	*(*(gm->map + gm->ply.y) + gm->ply.x) = SPACE;
	*(*(gm->map + gm->ply.y + y) + gm->ply.x + x) = PLAYER;
	gm->ply.x += x;
	gm->ply.y += y;
	gm->ply.d = d;
	gm->ply.count += 1;
	ft_change_axi_position(gm, x, y);
}

int	ft_keyevents_hndl(int keysym, t_gmobj *gm)
{
	if (keysym == ESCAPE)
		ft_del_gmobj(gm, EXIT_SUCCESS);
	else if (keysym == SMALL_W || keysym == LARGE_W || keysym == ARROW_UP)
		ft_keyevent(gm, 0, -1, PL_B);
	else if (keysym == SMALL_A || keysym == LARGE_A || keysym == ARROW_LF)
		ft_keyevent(gm, -1, 0, PL_L);
	else if (keysym == SMALL_S || keysym == LARGE_S || keysym == ARROW_DW)
		ft_keyevent(gm, 0, 1, PL_F);
	else if (keysym == SMALL_D || keysym == LARGE_D || keysym == ARROW_RG)
		ft_keyevent(gm, 1, 0, PL_R);
	return (0);
}
