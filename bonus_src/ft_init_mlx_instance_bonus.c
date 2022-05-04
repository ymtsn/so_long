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

#include "so_long_bonus.h"
#include "so_long_msg_bonus.h"
#include "so_long_xpm_bonus.h"
#include "so_long_img_index_bonus.h"
#include "so_long_drawing_bonus.h"
#define INIT_FAIL 1
#define INIT_SUCCESS 0

static void	ft_get_black_image(t_gmobj *gm)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(gm->mlx, &width, &height);
	gm->img[BLACK_IMG] = mlx_new_image (gm->mlx, width, IMG_PIXEL);
}

static void	ft_get_xpm_to_image(t_gmobj *gm)
{
	int		xy;

	xy = IMG_PIXEL;
	gm->img[SP] = mlx_xpm_file_to_image(gm->mlx, SPACE_X, &xy, &xy);
	gm->img[WL] = mlx_xpm_file_to_image(gm->mlx, WALL_X, &xy, &xy);
	gm->img[CL] = mlx_xpm_file_to_image(gm->mlx, COLLEC_X, &xy, &xy);
	gm->img[EX] = mlx_xpm_file_to_image(gm->mlx, EXIT_X, &xy, &xy);
	gm->img[PL_F] = mlx_xpm_file_to_image(gm->mlx, P_FR_00_X, &xy, &xy);
	gm->img[PL_F + 1] = mlx_xpm_file_to_image(gm->mlx, P_FR_01_X, &xy, &xy);
	gm->img[PL_F + 2] = mlx_xpm_file_to_image(gm->mlx, P_FR_02_X, &xy, &xy);
	gm->img[PL_B] = mlx_xpm_file_to_image(gm->mlx, P_BK_00_X, &xy, &xy);
	gm->img[PL_B + 1] = mlx_xpm_file_to_image(gm->mlx, P_BK_01_X, &xy, &xy);
	gm->img[PL_B + 2] = mlx_xpm_file_to_image(gm->mlx, P_BK_02_X, &xy, &xy);
	gm->img[PL_R] = mlx_xpm_file_to_image(gm->mlx, P_RG_00_X, &xy, &xy);
	gm->img[PL_R + 1] = mlx_xpm_file_to_image(gm->mlx, P_RG_01_X, &xy, &xy);
	gm->img[PL_R + 2] = mlx_xpm_file_to_image(gm->mlx, P_RG_02_X, &xy, &xy);
	gm->img[PL_L] = mlx_xpm_file_to_image(gm->mlx, P_LF_00_X, &xy, &xy);
	gm->img[PL_L + 1] = mlx_xpm_file_to_image(gm->mlx, P_LF_01_X, &xy, &xy);
	gm->img[PL_L + 2] = mlx_xpm_file_to_image(gm->mlx, P_LF_02_X, &xy, &xy);
	gm->img[EN_F] = mlx_xpm_file_to_image(gm->mlx, E_FR_X, &xy, &xy);
	gm->img[EN_B] = mlx_xpm_file_to_image(gm->mlx, E_BK_X, &xy, &xy);
	gm->img[EN_R] = mlx_xpm_file_to_image(gm->mlx, E_RG_X, &xy, &xy);
	gm->img[EN_L] = mlx_xpm_file_to_image(gm->mlx, E_LF_X, &xy, &xy);
}

static int	ft_get_image_instance(t_gmobj *gm)
{
	int	i;

	i = 0;
	ft_get_xpm_to_image(gm);
	ft_get_black_image(gm);
	while (i != IMG_CNT_MAX)
		if (gm->img[i++] == NULL)
			return (INIT_FAIL);
	return (INIT_SUCCESS);
}

static void	*ft_get_my_window(t_gmobj *gm)
{
	size_t	width;
	size_t	height;

	if (gm->map_x_len > WIN_SIZE_MAX)
		width = WIN_SIZE_MAX * IMG_PIXEL;
	else
		width = gm->map_x_len * IMG_PIXEL;
	if (gm->map_y_len > WIN_SIZE_MAX)
		height = (WIN_SIZE_MAX + 1) * IMG_PIXEL;
	else
		height = (gm->map_y_len + 1) * IMG_PIXEL;
	return (mlx_new_window(gm->mlx, width, height, W_TITLE));
}

void	ft_init_mlx_instance(t_gmobj *gm)
{
	gm->mlx = mlx_init();
	if (gm->mlx == NULL)
		ft_myexit(gm, MLX_INIT_FAIL, ft_del_gmobj, EXIT_FAILURE);
	gm->win = ft_get_my_window(gm);
	if (gm->win == NULL)
		ft_myexit(gm, MLX_INIT_FAIL, ft_del_gmobj, EXIT_FAILURE);
	if (ft_get_image_instance(gm) == INIT_FAIL)
		ft_myexit(gm, IMG_INIT_FAIL, ft_del_gmobj, EXIT_FAILURE);
}
