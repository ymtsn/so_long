/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:58:13 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/28 11:55:42 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_drawing.h"
#include "so_long_img_index.h"

int	ft_get_index(int mapobj)
{
	if (mapobj == COLLEC)
		return (2);
	else if (mapobj == PLAYER)
		return (3);
	else
		return (1);
	return (0);
}

void	ft_draw_initialize(void *vgm, size_t *x, size_t *y)
{
	(void)vgm;
	*x = 0;
	*y = 0;
}

void	ft_draw_objects(void *vgm, size_t *x, size_t *y)
{
	int		index;
	t_gmobj	*gm;
	size_t	x_pos;
	size_t	y_pos;

	gm = (t_gmobj *)vgm;
	if (gm->drw.mapobj == SPACE)
		index = SP;
	else if (gm->drw.mapobj == WALL)
		index = WL;
	else
		index = EX;
	x_pos = *x * IMG_PIXEL;
	y_pos = *y * IMG_PIXEL;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[index], x_pos, y_pos);
}

void	ft_draw_collect(void *vgm, size_t *x, size_t *y)
{
	t_gmobj	*gm;
	size_t	x_pos;
	size_t	y_pos;

	gm = (t_gmobj *)vgm;
	x_pos = *x * IMG_PIXEL;
	y_pos = *y * IMG_PIXEL;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[CL], x_pos, y_pos);
}

void	ft_draw_player(void *vgm, size_t *x, size_t *y)
{
	t_gmobj	*gm;
	size_t	x_pos;
	size_t	y_pos;
	int		ply_d;

	gm = (t_gmobj *)vgm;
	ply_d = gm->ply.d;
	x_pos = *x * IMG_PIXEL;
	y_pos = *y * IMG_PIXEL;
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img[ply_d], x_pos, y_pos);
	gm->ply.win_x = *x;
	gm->ply.win_y = *y;
}
