/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:00:08 by fgori             #+#    #+#             */
/*   Updated: 2024/01/29 12:03:01 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <pthread.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_data
{
	void			*floor;
	void			*wall;
	void			*wall1;
	void			*wall3;
	void			*exit_off;
	void			*exit_on;
	void			*collect;
	void			*god_finish;
	void			*ch1;
	void			*shr1;
	void			*shr2;
	void			*shl1;
	void			*shl3;
	void			*shu1;
	void			*shu3;
	void			*shd1;
	void			*shd2;
	void			*shx1;
	void			*shx2;
	void			*shx3;
	void			*shx4;
	void			*shx5;
	void			*shx6;
	void			*shx7;
	void			*shx8;
	void			*mon0;
	void			*mon2;
	void			*mon4;
	void			*mon6;
	void			*mon7;
	void			*mon10;
	void			*mon11;
	void			*mon13;
	void			*mon14;
	void			*mon15;
	void			*mon16;
	void			*mon17;
	void			*mon18;
	void			*mlx_ptr;
	void			*win_ptr;

	char			**map;
	char			**copy;

	int				heightmap;
	int				basemap;
	int				move;
	int				finish;
	int				collectible;
	int				p_x;
	int				p_y;
	int				m_x;
	int				m_y;
	int				e_y;
	int				e_x;
	int				esistence;
}	t_data;

int		on_destroy(t_data *data);
int		check_wall(char *str, int num);
int		on_keypress(int keysym, t_data *data);
int		makemap(t_data *data, char *map);
int		map_chek(t_data *data, int row, char **temp);
int		map_rectngl(t_data *data);
int		is_playble(t_data *data);
int		finalwall(t_data *data);
int		p_move_up(t_data *data);
int		p_move_down(t_data *data);
int		p_move_right(t_data *data);
int		p_move_left(t_data *data);
int		fullfill(char **map, int h, int n, t_data *data);
int		loop_moster(void *arg);
void	freeall(char **mat);
void	convert_img(t_data *data);
void	put_image(t_data *data);
void	put_move(t_data *data);
void	replace(t_data *data, char goal);
void	deadline(t_data *data, int x, int y);
int		moster_move(t_data *data);
void	moster_move_two(t_data *data);
void	moster_move_tree(t_data *data);
void	moster_move_four(t_data *data);
void	replace_moster(t_data *data, int mx, int my);
void	free_imag(t_data *data);
void	end_game(t_data *data);
void	set_struct(t_data *data);
void	set_struct_two(t_data *data);
void	set_struct_tree(t_data *data);
void	wincondition(t_data *data);

#endif