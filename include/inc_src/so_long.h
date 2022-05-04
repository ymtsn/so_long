/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:32:15 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/27 08:49:56 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# define IMG_CNT_MAX 20
# define FUNCPTR_CNT_MAX 3
typedef struct s_ply
{
	int	x;
	int	y;
	int	d;
	int	count;
	int	axi_x;
	int	axi_y;
	int	win_x;
	int	win_y;
}	t_ply;
typedef struct s_eny
{
	int	y;
	int	x;
	int	d;
}	t_eny;
typedef struct s_drw
{
	int		mapobj;
	void	(*func[FUNCPTR_CNT_MAX + 1])(void *, size_t *, size_t *);
}	t_drw;
typedef struct s_gmobj
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img[IMG_CNT_MAX + 1];
	size_t	map_x_len;
	size_t	map_y_len;
	int		flg_exit;
	size_t	collec_cnt;
	t_ply	ply;
	t_eny	eny;
	t_drw	drw;
}	t_gmobj;
/* ft_change_axi_position.c */
void	ft_change_axi_position(t_gmobj *gm, int x, int y);
/* ft_check_filename.c */
void	ft_check_filename(char *filename);
/* ft_check_map_char.c */
int		ft_check_map_char(char *map);
/* ft_check_map_rect.c */
int		ft_check_map_rect(t_gmobj *gm, char **map);
/* ft_draw_map.c */
int		ft_draw_map(t_gmobj *gm);
/* ft_draw_utils.c */
int		ft_get_index(int mapboj);
void	ft_draw_initialize(void *gm, size_t *x, size_t *y);
void	ft_draw_objects(void *gm, size_t *x, size_t *y);
void	ft_draw_collect(void *gm, size_t *x, size_t *y);
void	ft_draw_player(void *gm, size_t *x, size_t *y);
/* get_file_to_str.c */
char	*ft_get_file_to_str(int fd);
/* ft_init_draw_utils_func_ptr.c */
void	ft_init_draw_utils_func_ptr(t_gmobj *gm);
/* ft_init_game_parametor.c */
void	ft_init_game_parametor(t_gmobj *gm);
/* ft_init_map.c */
void	ft_init_mapdata(t_gmobj *gm, char *mappath);
/* ft_init_mlxinstance.c */
void	ft_init_mlx_instance(t_gmobj *gm);
/* ft_keyevent.c */
int		ft_keyevents_hndl(int keycode, t_gmobj *gm);
/* ft_so_long_utils.c */
void	ft_myexit(t_gmobj *gm, char *msg, int (*f)(t_gmobj*, int), int exitcd);
int		ft_del_gmobj(t_gmobj *gm, int exitcd);
void	ft_cleanmap(char **map);
int		ft_mydosync(t_gmobj *gm);
#endif
