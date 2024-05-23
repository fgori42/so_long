/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:20:21 by fgori             #+#    #+#             */
/*   Updated: 2024/01/25 12:03:47 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->exit_on, data->e_x * 64, data->e_y * 64);
	mlx_do_sync(data->mlx_ptr);
	data->finish = 1;
}

void	free_img_four(t_data *data)
{
	if (data->mon15)
		mlx_destroy_image(data->mlx_ptr, data->mon15);
	if (data->god_finish)
		mlx_destroy_image(data->mlx_ptr, data->god_finish);
}

void	free_img_tree(t_data *data)
{
	if (data->shu3)
		mlx_destroy_image(data->mlx_ptr, data->shu3);
	if (data->shr1)
		mlx_destroy_image(data->mlx_ptr, data->shr1);
	if (data->shr2)
		mlx_destroy_image(data->mlx_ptr, data->shr2);
	if (data->mon0)
		mlx_destroy_image(data->mlx_ptr, data->mon0);
	if (data->mon2)
		mlx_destroy_image(data->mlx_ptr, data->mon2);
	if (data->mon4)
		mlx_destroy_image(data->mlx_ptr, data->mon4);
	if (data->mon6)
		mlx_destroy_image(data->mlx_ptr, data->mon6);
	if (data->mon7)
		mlx_destroy_image(data->mlx_ptr, data->mon7);
	if (data->mon10)
		mlx_destroy_image(data->mlx_ptr, data->mon10);
	if (data->mon11)
		mlx_destroy_image(data->mlx_ptr, data->mon11);
	if (data->mon13)
		mlx_destroy_image(data->mlx_ptr, data->mon13);
	if (data->mon14)
		mlx_destroy_image(data->mlx_ptr, data->mon14);
	free_img_four(data);
}

void	free_img_two(t_data *data)
{
	if (data->collect)
		mlx_destroy_image(data->mlx_ptr, data->collect);
	if (data->shx1)
		mlx_destroy_image(data->mlx_ptr, data->shx1);
	if (data->shx2)
		mlx_destroy_image(data->mlx_ptr, data->shx2);
	if (data->shx3)
		mlx_destroy_image(data->mlx_ptr, data->shx3);
	if (data->shx4)
		mlx_destroy_image(data->mlx_ptr, data->shx4);
	if (data->shx5)
		mlx_destroy_image(data->mlx_ptr, data->shx5);
	if (data->shx6)
		mlx_destroy_image(data->mlx_ptr, data->shx6);
	if (data->shx7)
		mlx_destroy_image(data->mlx_ptr, data->shx7);
	if (data->shx8)
		mlx_destroy_image(data->mlx_ptr, data->shx8);
	if (data->mon16)
		mlx_destroy_image(data->mlx_ptr, data->mon16);
	if (data->mon17)
		mlx_destroy_image(data->mlx_ptr, data->mon17);
	if (data->mon18)
		mlx_destroy_image(data->mlx_ptr, data->mon18);
	free_img_tree(data);
}

void	free_imag(t_data *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->wall1)
		mlx_destroy_image(data->mlx_ptr, data->wall1);
	if (data->wall3)
		mlx_destroy_image(data->mlx_ptr, data->wall3);
	if (data->exit_off)
		mlx_destroy_image(data->mlx_ptr, data->exit_off);
	if (data->exit_on)
		mlx_destroy_image(data->mlx_ptr, data->exit_on);
	if (data->ch1)
		mlx_destroy_image(data->mlx_ptr, data->ch1);
	if (data->shd1)
		mlx_destroy_image(data->mlx_ptr, data->shd1);
	if (data->shd2)
		mlx_destroy_image(data->mlx_ptr, data->shd2);
	if (data->shl1)
		mlx_destroy_image(data->mlx_ptr, data->shl1);
	if (data->shl3)
		mlx_destroy_image(data->mlx_ptr, data->shl3);
	if (data->shu1)
		mlx_destroy_image(data->mlx_ptr, data->shu1);
	free_img_two(data);
}
