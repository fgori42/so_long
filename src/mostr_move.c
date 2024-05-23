/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mostr_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:46:34 by fgori             #+#    #+#             */
/*   Updated: 2024/01/26 14:05:34 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moster_move(t_data *data)
{
	if (data->esistence == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mon0, data->m_x * 64, data->m_y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(30000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mon2, data->m_x * 64, data->m_y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(30000);
		moster_move_two(data);
	}
	return (0);
}

void	moster_move_two(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon4, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon6, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon7, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	moster_move_tree(data);
}

void	moster_move_tree(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon10, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon11, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon13, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon14, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->floor, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
}

void	moster_move_four(t_data *data)
{
	int		randnum;
	char	**temp;
	int		my;
	int		mx;

	temp = data->map;
	my = data->m_y;
	mx = data->m_x;
	srandom(time(NULL));
	randnum = random() % 4;
	if (data->esistence != 1)
		return ;
	if (randnum == 0 && temp[my + 1][mx] != '1'
		&& temp[my + 1][mx] != 'C' && temp[my + 1][mx] != 'E')
		data->m_y += 1;
	if (randnum == 1 && temp[my - 1][mx] != '1'
		&& temp[my - 1][mx] != 'C' && temp[my - 1][mx] != 'E')
		data->m_y += -1;
	if (randnum == 2 && temp[my][mx + 1] != '1'
		&& temp[my][mx + 1] != 'C' && temp[my][mx + 1] != 'E')
		data->m_x += 1;
	if (randnum == 3 && temp[my][mx - 1] != '1'
		&& temp[my][mx - 1] != 'C' && temp[my][mx - 1] != 'E')
		data->m_x += -1;
	replace_moster(data, mx, my);
}

void	replace_moster(t_data *data, int mx, int my)
{
	data->map[my][mx] = '0';
	data->map[data->m_y][data->m_x] = 'M';
	if (data->m_y == data->p_y && data->p_x == data->m_x)
		deadline(data, data->m_x * 64, data->m_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon15, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon16, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon17, data->m_x * 64, data->m_y * 64);
	mlx_do_sync(data->mlx_ptr);
	usleep(30000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->mon0, data->m_x * 64, data->m_y * 64);
}
