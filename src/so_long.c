/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:04 by fgori             #+#    #+#             */
/*   Updated: 2024/05/29 21:02:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	if (data->god_finish)
		free_imag(data);
	if (data->map)
		freeall(data->map);
	if (data->copy)
		freeall(data->copy);
	if (data->win_ptr)
		mlx_destroy_window(data-> mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		return (p_move_up(data));
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		return (p_move_down(data));
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		return (p_move_right(data));
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		return (p_move_left(data));
	if (keysym == XK_Escape)
	{
		on_destroy(data);
	}
	return (0);
}

int	loop_moster(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(150000);
	moster_move(data);
	moster_move_four(data);
	return (0);
}

void	make_str(int fd, int len)
{
	int	i;
	int cha;

	i = 0;
	ft_putchar('1', fd);
	while (i < len - 2)
	{
		srandom(time(NULL));
		cha = random() % 10;
		if (cha < 3)
			ft_putchar('1', fd);
		if (cha >= 3 && cha < 6)
			ft_putchar('0', fd);
	}
}

int	auto_mapping(void)
{
	int	len;
	int	cont;
	int	i;
	int	len_two;
	int	fd;

	i = 0;
	len_two = 1;
	srandom(time(NULL));
	len = random() % 20;
	fd =  open("temp_map", O_TRUNC | O_CREAT | O_RDWR, 0777);
	while (i < len)
	{
		ft_putchar_fd('1', fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
	while(len_two < len - 2)
	{
		i = 0;
		while(i < len)
		{
			make_str(fd, len);
			i++;
		}
		len_two++;
	}
	return (fd);
}

void	so_long(t_data *data, char *av)
{
	set_struct(data);
	set_struct_two(data);
	set_struct_tree(data);
	if (makemap(data, av) == -1)
		on_destroy(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	convert_img(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->basemap - 1) * 64,
			data->heightmap * 64, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr));
	put_image(data);
	put_move(data);
	mlx_key_hook(data->win_ptr, &on_keypress, data);
	mlx_hook(data->win_ptr, 33, 1L << 5, &on_destroy, data);
	mlx_loop_hook(data->mlx_ptr, loop_moster, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	so_long(&data, av[1]);
	return (0);
}
