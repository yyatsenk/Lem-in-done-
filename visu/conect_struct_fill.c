/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conect_struct_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 09:40:16 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/17 09:40:17 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static	char	**help_me_please(t_room **room_copy, t_room **room_copy_2,
	t_room *room, char *str)
{
	char		**str_sp;

	*room_copy = room->next;
	*room_copy_2 = room->next;
	str_sp = ft_strsplit(str, '-');
	while ((*room_copy)->next && ft_strcmp((*room_copy)->room_name, str_sp[0]))
		*room_copy = (*room_copy)->next;
	while ((*room_copy_2)->next &&
		ft_strcmp((*room_copy_2)->room_name, str_sp[1]))
		(*room_copy_2) = (*room_copy_2)->next;
	if ((*room_copy)->is_end != 1)
		(*room_copy)->down = add_rebro(rebro_init((*room_copy_2)->index),\
		(*room_copy)->down);
	else
		(*room_copy_2)->down = add_rebro(rebro_init((*room_copy)->index),\
			(*room_copy_2)->down);
	(*room_copy) = room->next;
	(*room_copy_2) = room->next;
	while ((*room_copy)->next && ft_strcmp((*room_copy)->room_name,\
		str_sp[0]))
		(*room_copy) = (*room_copy)->next;
	while ((*room_copy_2)->next && ft_strcmp((*room_copy_2)->room_name,\
	str_sp[1]))
		(*room_copy_2) = (*room_copy_2)->next;
	return (str_sp);
}

static	int		test(char **str_sp, t_room *room_copy, t_room *room_copy_2)
{
	if ((ft_strcmp(room_copy->room_name, str_sp[0])
	|| ft_strcmp(room_copy_2->room_name, str_sp[1])))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}

static int		yes(int res, t_data *data, char *str, t_room *room)
{
	if (res == 3)
		return (3);
	if (res != 1)
	{
		free(str);
		get_next_line(0, &str);
		data = add_data(data, data_init(ft_strdup(str)));
		return (2);
	}
	if (!room->next && (res = 3))
		return (3);
	return (1);
}

static int		please(char *str, t_data *data, t_room *room, char **str_sp)
{
	int			res;
	t_room		*r_c;
	t_room		*r_c_2;
	int			check;

	while ((res = connection_valid_check(str)))
	{
		r_c = room->next;
		r_c_2 = room->next;
		if ((check = yes(res, data, str, room)) == 3)
			break ;
		if (check == 2)
			continue ;
		str_sp = help_me_please(&r_c, &r_c_2, room, str);
		if (!test(str_sp, r_c, r_c_2))
			return (0);
		if (r_c->is_end != 1)
			r_c_2->down = add_rebro(rebro_init(r_c->index), r_c_2->down);
		else
			r_c->down = add_rebro(rebro_init(r_c_2->index), r_c->down);
		free(str);
		get_next_line(0, &str);
		data = add_data(data, data_init(ft_strdup(str)));
	}
	return (res);
}

int				conect_struct_fill(t_room *room, int num_of_ants,
	char *str, t_data *data)
{
	t_room		*room_copy;
	t_room		*room_copy_2;
	int			res;
	char		**str_sp;

	if (str && !str[0])
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	if ((res = please(str, data, room, str_sp)) == 0)
		return (0);
	if (res != 3 || (res = check_end_start(room->next)) || num_of_ants < 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	return (1);
}
