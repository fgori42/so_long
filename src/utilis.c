/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:55 by fgori             #+#    #+#             */
/*   Updated: 2024/01/25 13:51:38 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deadline(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx1, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx2, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx3, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx4, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx5, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx6, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx7, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(100000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->shx8, x, y);
	mlx_do_sync(data->mlx_ptr);
	usleep(1000000);
	on_destroy(data);
}

void	set_struct(t_data *data)
{
	data->heightmap = 0;
	data->basemap = 0;
	data->move = 0;
	data->finish = 0;
	data->collectible = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->m_x = 0;
	data->m_y = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->esistence = 0;
	data->map = NULL;
	data->copy = NULL;
	data->floor = NULL;
	data->wall = NULL;
	data->wall1 = NULL;
	data->wall3 = NULL;
	data->exit_off = NULL;
	data->exit_on = NULL;
	data->collect = NULL;
	data->ch1 = NULL;
	data->shd1 = NULL;
	data->god_finish = NULL;
	set_struct_two(data);
}

void	set_struct_two(t_data *data)
{
	data->shd2 = NULL;
	data->shl1 = NULL;
	data->shl3 = NULL;
	data->shr1 = NULL;
	data->shr2 = NULL;
	data->shu1 = NULL;
	data->shu3 = NULL;
	data->shx1 = NULL;
	data->shx2 = NULL;
	data->shx3 = NULL;
	data->shx4 = NULL;
	data->shx5 = NULL;
	data->shx6 = NULL;
	data->shx7 = NULL;
	data->shx8 = NULL;
	data->mon0 = NULL;
	data->mon2 = NULL;
	data->mon4 = NULL;
	data->mon6 = NULL;
	data->mon7 = NULL;
	data->mon10 = NULL;
	data->mon11 = NULL;
	data->mon13 = NULL;
	data->mon14 = NULL;
	set_struct_tree(data);
}

void	set_struct_tree(t_data *data)
{
	data->mon15 = NULL;
	data->mon16 = NULL;
	data->mon17 = NULL;
	data->mon18 = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

void	wincondition(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->god_finish,
		((((data->basemap - 1) / 2) * 64) - 96),
		((((data->heightmap - 1) / 2) * 64) - 96));
	mlx_do_sync(data->mlx_ptr);
	sleep(3);
	on_destroy(data);
}
