/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:28:06 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 15:48:17 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long_msg_bonus.h"
#include "so_long_drawing_bonus.h"
#include "so_long_img_index_bonus.h"
#include "libft.h"
#include <unistd.h>

void	ft_draw_steps(t_gmobj *gm)
{
	char	*str;

	str = ft_itoa(gm->ply.count);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[BLACK_IMG], 0, 0);
	mlx_string_put(gm->mlx, gm->win, 16, 16, 0XFFFFFFFF, str);
	free(str);
}

void	ft_animation(t_gmobj *gm, size_t x, size_t y)
{
	int		index;
	size_t	x_pos;
	size_t	y_pos;

	x_pos = x * IMG_PIXEL;
	y_pos = y * IMG_PIXEL;
	usleep(100000);
	index = gm->ply.d + 1;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[index], x_pos, y_pos);
	mlx_do_sync(gm->mlx);
	usleep(100000);
	index = gm->ply.d + 2;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[index], x_pos, y_pos);
	mlx_do_sync(gm->mlx);
}

void	ft_die(t_gmobj *gm)
{
	size_t	x_pos;
	size_t	y_pos;
	int		flg;

	flg = 0;
	if (*(*(gm->map + gm->ply.y) + gm->ply.x + 1) == ENEMY)
		flg = 1;
	if (!flg && (*(*(gm->map + gm->ply.y) + gm->ply.x - 1) == ENEMY))
		flg = 1;
	if (!flg && (*(*(gm->map + gm->ply.y + 1) + gm->ply.x) == ENEMY))
		flg = 1;
	if (!flg && (*(*(gm->map + gm->ply.y - 1) + gm->ply.x) == ENEMY))
		flg = 1;
	if (flg)
	{
		x_pos = gm->ply.win_x * IMG_PIXEL;
		y_pos = gm->ply.win_y * IMG_PIXEL;
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[PL_F], x_pos, y_pos);
		mlx_do_sync(gm->mlx);
		sleep(1);
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img[EN_F], x_pos, y_pos);
		mlx_do_sync(gm->mlx);
		sleep(1);
		ft_myexit(gm, YOUDIED, ft_del_gmobj, EXIT_SUCCESS);
	}
}

void	ft_game_effect(t_gmobj *gm)
{
	ft_die(gm);
	ft_draw_steps(gm);
	ft_animation(gm, gm->ply.win_x, gm->ply.win_y);
}

int	ft_draw_map(t_gmobj *gm)
{
	size_t	x;
	size_t	y;
	size_t	ax;
	size_t	ay;

	gm->drw.func[0](gm, &x, &y);
	ax = gm->ply.axi_x;
	ay = gm->ply.axi_y;
	ft_enemy_move_hndl(gm);
	while (*(gm->map + ay + y) != NULL && y < WIN_SIZE_MAX)
	{
		while ((*(*(gm->map + ay + y) + ax + x) != '\0') && x < WIN_SIZE_MAX)
		{
			gm->drw.mapobj = *(*(gm->map + ay + y) + ax + x);
			gm->drw.func[ft_get_index(gm->drw.mapobj)](gm, &x, &y);
			x++;
		}
		x = 0;
		y++;
	}
	ft_game_effect(gm);
	if (gm->collec_cnt == 0)
		gm->flg_exit = 1;
	return (0);
}
