/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:28:06 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 09:24:24 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_drawing.h"

int	ft_draw_map(t_gmobj *gm)
{
	size_t	x;
	size_t	y;
	size_t	ax;
	size_t	ay;

	gm->drw.func[0](gm, &x, &y);
	ax = gm->ply.axi_x;
	ay = gm->ply.axi_y;
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
	if (gm->collec_cnt == 0)
		gm->flg_exit = 1;
	return (0);
}
