/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:21:57 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/17 11:21:58 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int		help1(int *j, t_way **way_rotate,
	t_room **room_copy, t_rebro **r_copy_down)
{
	t_way_down	*down_copy;

	if (++(*j) != 0)
		(*way_rotate) = (*way_rotate)->next;
	if (!*way_rotate)
		return (3);
	down_copy = (*way_rotate)->down;
	while ((*way_rotate)->down->next)
		(*way_rotate)->down = (*way_rotate)->down->next;
	while ((*room_copy)->index != (*way_rotate)->down->elem)
		(*room_copy) = (*room_copy)->next;
	(*way_rotate)->down = down_copy;
	*r_copy_down = (*room_copy)->down;
	return (1);
}

static void		help(t_way **way, t_room **room_copy, t_way **way_rotate)
{
	*way = way_init(0, 0);
	while ((*room_copy)->next && (*room_copy)->is_start != 1)
		(*room_copy) = (*room_copy)->next;
	(*way)->down = add_way_down(way_down_init((*room_copy)->index, 0),\
		(*way)->down);
	(*room_copy)->is_visited = 1;
	*way_rotate = *way;
}

static int		help_2(t_room **room_copy_2, t_room **room_copy, t_room **room)
{
	*room_copy_2 = (*room)->next;
	while ((*room_copy_2)->index != (*room_copy)->down->index_of_elem)
		(*room_copy_2) = (*room_copy_2)->next;
	if ((*room_copy_2)->is_visited)
	{
		(*room_copy)->down = (*room_copy)->down->next;
		return (3);
	}
	return (1);
}

static void		help_3(t_way **way, t_room **room_copy)
{
	t_way		*way_copy;
	t_way		*w_c_2;

	w_c_2 = *way;
	while (w_c_2->next)
		w_c_2 = w_c_2->next;
	way_copy = *way;
	while (way_copy->num_of_way != w_c_2->parent)
		way_copy = way_copy->next;
	w_c_2->down = w_down_copy(way_copy->down);
	w_c_2->down = add_way_down(way_down_init((*room_copy)->down->index_of_elem,\
		(0)), w_c_2->down);
	(*room_copy)->down = (*room_copy)->down->next;
}

t_way			*make_ways(t_room *room, t_room *room_copy,\
	t_room *room_copy_2, int count)
{
	t_way		*way;
	int			j;
	t_rebro		*r_copy_down;
	t_way		*way_rotate;

	j = -1;
	help(&way, &room_copy, &way_rotate);
	while (1)
	{
		room_copy = room->next;
		if ((help1(&j, &way_rotate, &room_copy, &r_copy_down)) == 3)
			break ;
		while (room_copy->down)
		{
			if (help_2(&room_copy_2, &room_copy, &room) == 3)
				continue ;
			way = add_way(way_init(++count, way_rotate->num_of_way), way);
			help_3(&way, &room_copy);
		}
		room_copy->down = r_copy_down;
		if (room_copy->is_end != 1)
			room_copy->is_visited = 1;
	}
	return (way);
}
