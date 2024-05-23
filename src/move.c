/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:14:25 by fgori             #+#    #+#             */
/*   Updated: 2024/01/25 13:29:39 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	p_move_up(t_data *data)
{
	char	**temp;
	int		*x;
	int		*y;

	temp = data->map;
	y = &data->p_y;
	x = &data->p_x;
	if (temp[*y - 1][*x] != '1' &&
		(temp[*y - 1][*x] != 'E' || data->finish == 1))
	{
		moster_move(data);
		data->move += 1;
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shu1, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shu3, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		replace(data, 'u');
		put_move(data);
		return (0);
	}
	return (0);
}

int	p_move_right(t_data *data)
{
	char	**temp;
	int		*x;
	int		*y;

	temp = data->map;
	y = &data->p_y;
	x = &data->p_x;
	if (temp[*y][*x + 1] != '1' &&
		(temp[*y][*x + 1] != 'E' || data->finish == 1))
	{
		moster_move(data);
		data->move += 1;
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shr1, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shr2, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		replace(data, 'r');
		put_move(data);
		return (0);
	}
	return (0);
}

int	p_move_left(t_data *data)
{
	char	**temp;
	int		*x;
	int		*y;

	temp = data->map;
	y = &data->p_y;
	x = &data->p_x;
	if (temp[*y][*x - 1] != '1' &&
		(temp[*y][*x - 1] != 'E' || data->finish == 1))
	{
		moster_move(data);
		data->move += 1;
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shl1, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shl3, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		replace(data, 'l');
		put_move(data);
		return (0);
	}
	return (0);
}

int	p_move_down(t_data *data)
{
	char	**temp;
	int		*x;
	int		*y;

	temp = data->map;
	y = &data->p_y;
	x = &data->p_x;
	if (temp[*y + 1][*x] != '1' &&
		(temp[*y + 1][*x] != 'E' || data->finish == 1))
	{
		moster_move(data);
		data->move += 1;
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shd1, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->shd2, *x * 64, *y * 64);
		mlx_do_sync(data->mlx_ptr);
		usleep(80000);
		replace(data, 'd');
		put_move(data);
		return (0);
	}
	return (0);
}

void	replace(t_data *data, char goal)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->floor, data->p_x * 64, data->p_y * 64);
	if (goal == 'u')
		data->p_y -= 1;
	if (goal == 'd')
		data->p_y += 1;
	if (goal == 'r')
		data->p_x += 1;
	if (goal == 'l')
		data->p_x -= 1;
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->ch1, data->p_x * 64, data->p_y * 64);
	mlx_do_sync(data->mlx_ptr);
	moster_move_four(data);
	if (data->map[data->p_y][data->p_x] == 'C')
	{
		data->collectible--;
		data->map[data->p_y][data->p_x] = '0';
		if (data->collectible == 0)
			end_game(data);
	}
	if (data->map[data->p_y][data->p_x] == 'E')
		wincondition(data);
	if (data->map[data->p_y][data->p_x] == 'M')
		deadline(data, data->p_x * 64, data->p_y * 64);
}
