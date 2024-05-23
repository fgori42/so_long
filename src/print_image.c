/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:25 by fgori             #+#    #+#             */
/*   Updated: 2024/01/24 15:58:49 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_element(char find, int x, int y, t_data *data)
{
	if (find == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->ch1, x * 64, y * 64);
	else if (find == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->collect, x * 64, y * 64);
	else if (find == '1' && x < data->basemap - 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall, x * 64, y * 64);
	else if (find == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->floor, x * 64, y * 64);
	else if (find == 'M')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->mon0, x * 64, y * 64);
	else if (find == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_off, x * 64, y * 64);
}

void	put_last(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->basemap - 1)
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall3, x * 64, y * 64);
		x++;
	}
}

void	put_move(t_data *data)
{
	char	*str;
	char	*mov;
	char	*join;

	str = "MOVES : ";
	mov = ft_itoa(data-> move);
	join = ft_strjoin(str, mov);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->wall3, 64, (data->heightmap - 1) * 64);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		30, data->heightmap * 62, 0xffffff, join);
	free(mov);
	free(join);
}

void	put_image(t_data *data)
{
	int		x;
	int		y;
	char	***temp;

	y = 0;
	x = 0;
	temp = &(data->map);
	while ((*temp)[0][x] != '\0')
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall1, x * 64, y * 64);
		x++;
	}
	y = 1;
	while (y < data->heightmap - 1)
	{
		x = 0;
		while ((*temp)[y][x] != '\0')
		{
			put_element((*temp)[y][x], x, y, data);
			x++;
		}
		y++;
	}
	put_last(data, y);
}
