/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_get_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:38:35 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/17 14:38:36 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void		thanks(t_way **way_copy, t_ant **ant_copy, int mini_ant)
{
	t_way_down	*down;

	down = (*way_copy)->down;
	while ((*ant_copy)->num_of_ant != mini_ant)
		*ant_copy = (*ant_copy)->next;
	(*ant_copy)->way = down;
}

static void		help_0(t_room *room, int num_of_ants, t_ant **ant, t_way **way)
{
	t_room		*room_copy;
	int			mini_ant;
	t_ant		*ant_copy;
	t_way		*way_copy;
	int			min_way;

	mini_ant = 0;
	min_way = 0;
	room_copy = room->next;
	while (room_copy && !(room_copy->is_visited = 0))
		room_copy = room_copy->next;
	room_copy = room->next;
	while (room_copy->is_start != 1)
		room_copy = room_copy->next;
	while (mini_ant != num_of_ants)
	{
		way_copy = *way;
		*ant = ant_add(ant_init(++mini_ant), *ant);
		ant_copy = *ant;
		min_way = shortest(way_copy);
		while (way_copy->weight != min_way)
			way_copy = way_copy->next;
		way_copy->weight++;
		thanks(&way_copy, &ant_copy, mini_ant);
	}
}

static void		thanks_2(t_room *room, t_ant **ant_copy,\
	int *got_end, t_room *room_copy)
{
	t_room		*now_room;
	t_room		*room_copy_3;

	now_room = room->next;
	room_copy_3 = room->next;
	while (now_room->index != (*ant_copy)->way->elem)
		now_room = now_room->next;
	while (room_copy->index != (*ant_copy)->way->next->elem)
		room_copy = room_copy->next;
	if (room_copy->is_visited == 0)
	{
		while (room_copy_3->index != (*ant_copy)->way->next->elem)
			room_copy_3 = room_copy_3->next;
		now_room->is_visited = 0;
		ft_printf("L%d-%s ", (*ant_copy)->num_of_ant, room_copy_3->room_name);
		if (room_copy->is_end != 1)
			room_copy->is_visited = 1;
		else if (!(*ant_copy)->way->next->next)
			(*got_end)++;
		if ((*ant_copy)->way->next)
			(*ant_copy)->way = (*ant_copy)->way->next;
	}
}

static void		help_2(int num_of_ants, t_ant **ant, t_room *room)
{
	int			got_end;
	t_ant		*ant_copy;
	t_room		*room_copy;

	got_end = 0;
	while (got_end != num_of_ants)
	{
		ant_copy = *ant;
		while (ant_copy)
		{
			room_copy = room->next;
			if (ant_copy->way->next == NULL)
			{
				ant_copy = ant_copy->next;
				continue ;
			}
			thanks_2(room, &ant_copy, &got_end, room_copy);
			ant_copy = ant_copy->next;
		}
		ft_printf("\n");
	}
}

int				ants_get_way(t_way *way, t_data *data,\
	t_room *room, int num_of_ants)
{
	t_way		*way_copy;
	t_ant		*ant;
	t_data		*data_copy;

	ant = NULL;
	way = way_sort(way, room->next);
	if (!check_ignore(way))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	way_copy = way;
	help_0(room, num_of_ants, &ant, &way);
	data_copy = data;
	data = data->next;
	while (data->next)
	{
		ft_printf("%s\n", data->word);
		data = data->next;
	}
	ft_printf("\n");
	help_2(num_of_ants, &ant, room);
	free_ant(&ant);
	return (1);
}
