/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_maintain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:29:12 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:29:17 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_ant		*ant_add(t_ant *rebro_to_end, t_ant *begin)
{
	t_ant	*begin_copy;

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

t_ant		*ant_init(int num_of_ant)
{
	t_ant	*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->num_of_ant = num_of_ant;
	ant->next = NULL;
	ant->way = NULL;
	return (ant);
}

void		room_free(t_room *room)
{
	t_room	*room_copy;

	room_copy = room;
	while (room_copy)
	{
		if (room_copy->down)
			free(room_copy->down);
		free(room_copy->room_name);
		room_copy = room_copy->next;
	}
	free(room);
}

void		way_free(t_way *way)
{
	t_way	*way_copy;

	way_copy = way;
	while (way_copy)
	{
		if (way_copy->down)
			free(way_copy->down);
		way_copy = way_copy->next;
	}
	free(way);
}

void		data_free(t_data *data)
{
	t_data	*data_copy;

	data_copy = data;
	while (data_copy)
	{
		if (data_copy->word)
			free(data_copy->word);
		data_copy = data_copy->next;
	}
	free(data);
}
