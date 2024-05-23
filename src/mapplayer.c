/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgori <fgori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:40:00 by fgori             #+#    #+#             */
/*   Updated: 2024/04/09 14:53:44 by fgori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fullfill(char **map, int h, int n, t_data *data)
{
	int	ckex;

	ckex = 0;
	if (map[h][n] == 'E')
	{
		data->e_y = h;
		data->e_x = n;
		return (1);
	}
	if (map[h][n] == 'M')
	{
		data->m_x = n;
		data->m_y = h;
	}
	if (map[h][n] != '1' && map[h][n] != 'E' && map[h][n] != 'K')
	{
		map[h][n] = 'K';
		ckex += fullfill(map, h, n + 1, data);
		ckex += fullfill(map, h, n - 1, data);
		ckex += fullfill(map, h + 1, n, data);
		ckex += fullfill(map, h - 1, n, data);
	}
	return (ckex);
}

void	freeall(char **mat)
{
	int	n;

	n = 0;
	while (mat[n] != NULL)
	{
		free(mat[n]);
		mat[n] = NULL;
		n++;
	}
	free(mat);
}

int	finalwall(t_data *data)
{
	int		h;
	char	**temp;

	h = 0;
	temp = data->map;
	while (temp[h])
	{
		if (h < data->heightmap - 1)
			if (check_wall(temp[h], h) == -1)
				return (-1);
		if (h == data->heightmap - 1)
			if (check_wall(temp[h], 0) == -1)
				return (-1);
		h++;
	}
	return (is_playble(data));
}

int	is_playble(t_data *data)
{
	int		b;
	int		h;
	char	**temp;
	int		econt;

	h = 0;
	temp = data->copy;
	econt = fullfill(temp, data->p_y, data->p_x, data);
	if (econt == 0)
		return (perror("ERROR!\nincompletable"), -1);
	while (temp[h] != NULL)
	{
		b = 0;
		while (temp[h][b])
		{
			if (temp[h][b] == 'C')
				return (perror("ERROR!\nincompletable map\n"), -1);
			b++;
		}
		h++;
	}
	return (0);
}
