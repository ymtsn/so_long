/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gmo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:28:25 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/14 19:54:23 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_draw_utils_func_ptr(t_gmobj *gm)
{
	gm->drw.func[0] = ft_draw_initialize;
	gm->drw.func[1] = ft_draw_objects;
	gm->drw.func[2] = ft_draw_collect;
	gm->drw.func[3] = ft_draw_player;
}
