/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:18:28 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/18 16:18:30 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	size_coord_help(int *cof, int max, t_room **room_copy)
{
	while (*cof <= 0)
	{
		if (max < 1000)
			*cof = 14;
		if (max < 200)
			*cof = 12;
		if (max <= 25)
			*cof = 10;
		if (max >= 1000)
		{
			while (*room_copy)
			{
				while ((*room_copy)->coords.x >= 1000)
					(*room_copy)->coords.x = (*room_copy)->coords.x / 2;
				while ((*room_copy)->coords.y >= 1000)
					(*room_copy)->coords.y = (*room_copy)->coords.y / 2;
				(*room_copy) = (*room_copy)->next;
			}
			*cof = 12;
		}
	}
}

int			size_coords_sort(t_room *room)
{
	t_room	*room_copy;
	t_room	*room_copy_2;
	int		max;
	int		cof;

	max = -1;
	cof = -1;
	room_copy = room;
	room_copy_2 = room;
	while (room_copy)
	{
		if (room_copy->coords.x > max)
			max = room_copy->coords.x;
		if (room_copy->coords.y > max)
			max = room_copy->coords.y;
		room_copy = room_copy->next;
	}
	room_copy = room;
	size_coord_help(&cof, max, &room_copy);
	return (cof);
}

int			ft_abs(int num)
{
	return ((num >= 0) ? num : (-num));
}

void		make_line(void *mlx_ptr, void *win_ptr, t_cc c, char *room_name)
{
	int		deltax;
	int		deltay;
	int		signx;
	int		signy;
	int		error;

	deltax = abs(c.x1 - c.x0);
	deltay = abs(c.y1 - c.y0);
	signx = c.x0 < c.x1 ? 1 : -1;
	signy = c.y0 < c.y1 ? 1 : -1;
	error = deltax - deltay;
	mlx_pixel_put(mlx_ptr, win_ptr, c.x1, c.y1, GREEN);
	while (c.x0 != c.x1 || c.y0 != c.y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, c.x0, c.y0, GREEN);
		g_error2 = error * 2;
		if (g_error2 > -deltay && (c.x0 += signx))
			error -= deltay;
		if (g_error2 < deltax && (c.y0 += signy))
			error += deltax;
	}
	mlx_string_put(mlx_ptr, win_ptr, c.x0, c.y1, RED, room_name);
}

void		teplo_cof(void **mlx_ptr, void **win_ptr, int kof, int *cof)
{
	int		x;
	int		y;

	if (kof == 40)
		*cof = 10;
	else if (kof == 10)
		*cof = 12;
	else
		*cof = 14;
	if (g_teplo == 1)
	{
		x = -1;
		while (++x < *cof * 100)
		{
			y = -1;
			while (++y < *cof * 100)
				mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, TEPLO);
		}
	}
}
