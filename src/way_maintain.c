/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_maintain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:26:54 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:26:56 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_way			*way_init(int index, int parent)
{
	t_way		*way;

	way = (t_way*)malloc(sizeof(t_way));
	way->num_of_way = index;
	way->parent = parent;
	way->ignore = 0;
	way->weight = -1;
	way->next = NULL;
	way->down = NULL;
	return (way);
}

t_way			*add_way(t_way *rebro_to_end, t_way *begin)
{
	t_way		*begin_copy;

	begin_copy = begin;
	if (!begin)
		begin_copy = rebro_to_end;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = rebro_to_end;
	}
	return (begin_copy);
}

t_way			*way_sort(t_way *way, t_room *room)
{
	t_way		*begin;
	t_way_down	*down_copy;

	begin = way;
	while (room->is_end != 1)
		room = room->next;
	while (way)
	{
		down_copy = way->down;
		while (way->down && way->down->next)
			way->down = way->down->next;
		if (!way->down || way->down->elem != room->index)
			way->ignore = 1;
		else
			way->weight = list_size_down(down_copy);
		way->down = down_copy;
		way = way->next;
	}
	return (begin);
}

int				shortest(t_way *way)
{
	t_way		*begin;
	int			min;

	begin = way;
	min = 2147483647;
	while (way)
	{
		if (way->weight != -1 && way->weight < min)
			min = way->weight;
		way = way->next;
	}
	way = begin;
	return (min);
}
