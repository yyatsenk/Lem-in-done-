/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_down_maintain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:24:52 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:24:53 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_way_down		*add_way_down(t_way_down *rebro_to_end, t_way_down *begin)
{
	t_way_down	*begin_copy;

	begin_copy = begin;
	if (!begin)
		begin_copy = rebro_to_end;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = rebro_to_end;
		rebro_to_end->prev = begin;
	}
	return (begin_copy);
}

t_way_down		*way_down_init(int index, int distance)
{
	t_way_down	*way_down;

	way_down = (t_way_down*)malloc(sizeof(t_way_down));
	way_down->elem = index;
	way_down->distance = distance;
	way_down->next = NULL;
	way_down->prev = NULL;
	return (way_down);
}

t_way_down		*w_down_copy(t_way_down *list)
{
	t_way_down	*way_down;

	way_down = NULL;
	while (list)
	{
		way_down = add_way_down(way_down_init(list->elem, 0), way_down);
		list = list->next;
	}
	return (way_down);
}

int				list_size_down(t_way_down *list)
{
	int			i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
