/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:27:03 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/19 11:27:04 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		help_0(t_way **way, t_room *room)
{
	t_room		*room_copy;

	*way = way_sort(*way, room->next);
	if (!check_ignore(*way))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	room_copy = room->next;
	while (room_copy)
	{
		(room_copy)->is_visited = 0;
		(room_copy) = (room_copy)->next;
	}
	(room_copy) = room->next;
	while ((room_copy)->is_start != 1)
		(room_copy) = (room_copy)->next;
	return (1);
}

static void		help_1(t_ant **ant, int num_of_ants, t_way **way)
{
	int			min_way;
	int			mini_ant;
	t_way_down	*down;
	t_way		*way_copy;
	t_ant		*ant_copy;

	mini_ant = 0;
	min_way = 0;
	while (mini_ant != num_of_ants)
	{
		way_copy = *way;
		mini_ant++;
		*ant = ant_add(ant_init(mini_ant), *ant);
		ant_copy = *ant;
		min_way = shortest(way_copy);
		while (way_copy->weight != min_way)
			way_copy = way_copy->next;
		way_copy->weight++;
		down = way_copy->down;
		while (ant_copy->num_of_ant != mini_ant)
			ant_copy = ant_copy->next;
		ant_copy->way = down;
	}
}

static void		thanks(t_p *p, t_room *room)
{
	int			cof;

	cof = size_coords_sort(room->next);
	if (cof == 10)
		p->kof = 40;
	else if (cof == 12)
		p->kof = 5;
	else
		p->kof = 1;
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr,\
		100 * cof, 100 * cof, "Fucking ants");
	build_map(room->next, &p->mlx_ptr, &p->win_ptr, p->kof);
	mlx_key_hook(p->win_ptr, win_keys, (void*)p);
	mlx_loop(p->mlx_ptr);
}

static int		help_2(t_way *way, t_room *room, int num_of_ants, t_data *data)
{
	t_ant		*ant;
	t_room		*now_room;
	t_p			*p;
	t_data		*data_copy;

	ant = NULL;
	if (!help_0(&way, room))
		return (0);
	help_1(&ant, num_of_ants, &way);
	data_copy = data;
	data = data->next;
	while (data->next)
	{
		printf("%s\n", data->word);
		data = data->next;
	}
	printf("\n");
	p = p_init(num_of_ants, ant, room, now_room);
	thanks(p, room);
	free(ant);
	free(p);
	data_free(data_copy);
	return (1);
}

int				main(int argv, char **argc)
{
	char		*str;
	t_data		*data;
	t_room		*room;
	t_way		*way;
	int			num_of_ants;

	data = data_init(NULL);
	str = NULL;
	g_teplo = 0;
	if (!bonus(argv, argc, &g_teplo))
		return (0);
	if (first_moments(str, data, &num_of_ants) == 0)
		return (0);
	str = line_struct_fill(&room, str, &data);
	if (conect_struct_fill(room, num_of_ants, str, data) == 0)
		return (0);
	way = make_ways(room, room->next, room->next, 0);
	if (!help_2(way, room, num_of_ants, data))
		return (0);
	room_free(room);
	way_free(way);
	return (0);
}
