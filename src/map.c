/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:28:17 by fgori             #+#    #+#             */
/*   Updated: 2024/04/09 14:57:39 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char *str, int num)
{
	int	x;

	if (num == 0)
	{
		x = 0;
		while (str[x])
		{
			if (str[x] != '1')
				return (perror("ERROR!\nwallbreak"), -1);
			x++;
		}
	}
	else
	{
		if (str[0] != '1')
			return (perror("ERROR!\nwallbreak"), -1);
		x = 1;
		while (str[x] != '\0')
			x++;
		if (str[x - 1] != '1')
			return (perror("ERROR!\nwallbreak"), -1);
	}
	return (0);
}

int	map_rectngl(t_data *data)
{
	int		height;
	int		base;
	int		baseb;
	char	**temp;

	temp = data->map;
	height = 0;
	base = ft_strlen(temp[height]);
	while (temp[height] != NULL)
	{
		baseb = ft_strlen(temp[height]);
		if (baseb != base)
			return (perror("ERROR!\nnot rectangular"), -1);
		height++;
	}
	data->heightmap = height;
	data->basemap = base + 1;
	return (map_chek(data, -1, temp));
}

static int	take_elements(char find, int *obj, t_data *data)
{
	static int	mos;

	if (find == 'M')
		mos++;
	if (find == 'M')
		data->esistence += 1;
	if (find == 'P')
	{
		obj[0]++;
		return (1);
	}
	else if (find == 'E')
	{
		obj[1]++;
		return (0);
	}
	else if (find == 'C')
	{
		obj[2]++;
		return (0);
	}
	if ((find != 'M' && find != '1' && find != '0') || mos > 1)
		return (-1);
	else
		return (0);
}

int	map_chek(t_data *data, int h, char **temp)
{
	int		col;
	int		obj[3];
	int		find;

	obj[0] = 0;
	obj[1] = 0;
	obj[2] = 0;
	while (++h < data->heightmap)
	{
		col = -1;
		while (temp[h][++col] != '\0')
		{
			find = take_elements(temp[h][col], obj, data);
			if (find == 1)
				data->p_y = h;
			if (find == 1)
				data->p_x = col;
			if (find == -1)
				return (perror("ERROR\nalien char"), -1);
		}
	}
	data->collectible = obj[2];
	if (obj[0] != 1 || obj[1] != 1 || obj[2] < 1)
		return (perror("ERROR\nmissing elements\n"), -1);
	return (finalwall(data));
}

int	makemap(t_data *data, char *map)
{
	int		fd;
	char	*str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit (1);
	str = ft_calloc(5000, sizeof(char));
	if (!str)
		return (0);
	if (read(fd, str, 5000) == -1)
	{
		free(str);
		exit (1);
	}
	close(fd);
	if(str[0] == '\n' || str[0] == '\0')
		return(perror("invalid map"), -1);
	data->map = ft_split(str, '\n');
	data->copy = ft_split(str, '\n');
	if (!map)
		return (0);
	free(str);
	return (map_rectngl(data));
}

// int	main()
// {
// 	t_data	data;
// 	int		h = 0;
// 	char **temp;

// 	makemap(data, "map1.ber");
// 	temp = data.map;
// }