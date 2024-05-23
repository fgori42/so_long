/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:33:05 by fgori             #+#    #+#             */
/*   Updated: 2024/01/25 12:26:10 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_five(t_data *data, int *x)
{
	int	n;

	n = 192;
	data->mon17 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon17.xpm", x, x);
	data->mon18 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon18.xpm", x, x);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/collectible.xpm", x, x);
	data->god_finish = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/god_fin.xpm", &n, &n);
	if (!data->god_finish)
	{
		on_destroy(data);
	}
}

void	convert_four(t_data *data, int *x)
{
	data->mon6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon6.xpm", x, x);
	data->mon7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon7.xpm", x, x);
	data->mon10 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon10.xpm", x, x);
	data->mon11 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon11.xpm", x, x);
	data->mon13 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon13.xpm", x, x);
	data->mon14 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon14.xpm", x, x);
	data->mon15 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon15.xpm", x, x);
	data->mon16 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon16.xpm", x, x);
	convert_five(data, x);
}

void	convert_tree(t_data *data, int *x)
{
	data->shx2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef18.xpm", x, x);
	data->shx3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef19.xpm", x, x);
	data->shx4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef20.xpm", x, x);
	data->shx5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef21.xpm", x, x);
	data->shx6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef22.xpm", x, x);
	data->shx7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef23.xpm", x, x);
	data->shx8 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef24.xpm", x, x);
	data->mon0 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon0.xpm", x, x);
	data->mon2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon2.xpm", x, x);
	data->mon4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/moster/mon4.xpm", x, x);
	convert_four(data, x);
}

void	convert_two(t_data *data, int *x)
{
	data->shr1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef4.xpm", x, x);
	data->shr2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef5.xpm", x, x);
	data->shl1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef8.xpm", x, x);
	data->shl3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef10.xpm", x, x);
	data->shd1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef12.xpm", x, x);
	data->shd2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef13.xpm", x, x);
	data->shu1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef14.xpm", x, x);
	data->shu3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef16.xpm", x, x);
	data->shx1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef17.xpm", x, x);
	convert_tree(data, x);
}

void	convert_img(t_data *data)
{
	int		x;

	x = 64;
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/floor.xpm", &x, &x);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/wall/wall_colon.xpm", &x, &x);
	data->wall1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/wall/wall_up.xpm", &x, &x);
	data->wall3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/wall/wall_down.xpm", &x, &x);
	data->exit_off = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/exit/exit_off.xpm", &x, &x);
	data->exit_on = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/exit/exit_on.xpm", &x, &x);
	data->ch1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./asses/chef/chef1.xpm", &x, &x);
	convert_two(data, &x);
}
