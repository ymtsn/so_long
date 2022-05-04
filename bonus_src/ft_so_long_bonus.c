/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:28:06 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/29 14:00:12 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long_msg_bonus.h"
#include "libft.h"

static void	ft_hook_event(t_gmobj *gm)
{
	mlx_hook(gm->win, 17, 0L, &ft_del_gmobj, gm);
	mlx_hook(gm->win, 2, 1L << 0, &ft_keyevents_hndl, gm);
	mlx_hook(gm->win, 12, 1L << 15, &ft_mydosync, gm);
	mlx_do_key_autorepeatoff(gm->mlx);
	mlx_loop_hook(gm->mlx, &ft_draw_map, gm);
}

static void	ft_initial(t_gmobj *gm, char *arg)
{
	ft_bzero(gm, sizeof(t_gmobj));
	ft_init_mapdata(gm, arg);
	ft_init_mlx_instance(gm);
	ft_init_draw_utils_func_ptr(gm);
	ft_init_game_parametor(gm);
}

int	main(int argc, char *argv[])
{
	t_gmobj	gm;

	if (argc != 2)
		ft_myexit(NULL, INVALID_ARGC, NULL, EXIT_FAILURE);
	ft_check_filename(argv[1]);
	ft_initial(&gm, argv[1]);
	ft_hook_event(&gm);
	mlx_loop(gm.mlx);
	return (0);
}
