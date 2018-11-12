/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_maintain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:14:25 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:14:26 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	room_init_help(char *str, t_room **room)
{
	char	**str_copy;

	if (str && (line_check(str) == 1))
	{
		str_copy = ft_strsplit(str, ' ');
		(*room)->room_name = str_copy[0];
		(*room)->coords.x = ft_atoi(str_copy[1]);
		(*room)->coords.y = ft_atoi(str_copy[2]);
	}
	else
	{
		str_copy = NULL;
		(*room)->room_name = NULL;
		(*room)->coords.x = -1;
		(*room)->coords.y = -1;
	}
}

t_room		*room_init(char *str, t_room *room_1)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	if (room_1)
	{
		while (room_1->next)
			room_1 = room_1->next;
		room->index = room_1->index + 1;
	}
	else
		room->index = 0;
	room->is_visited = 0;
	room->down = NULL;
	room->is_end = 0;
	room->is_start = 0;
	room->next = NULL;
	room_init_help(str, &room);
	return (room);
}

t_room		*start_set(t_data ***data, int fd, char *str, t_room *room)
{
	t_room	*new;

	get_next_line(fd, &str);
	**data = add_data(**data, data_init(ft_strdup(str)));
	while (str && str[0] == '#')
	{
		free(str);
		get_next_line(fd, &str);
		**data = add_data(**data, data_init(ft_strdup(str)));
	}
	if (!line_check(str))
	{
		printf("ERROR\n");
		exit(1);
	}
	new = room_init(str, room);
	new->is_start = 1;
	free(str);
	room = add_back(new, room);
	return (room);
}

t_room		*end_set(t_data ***data, int fd, char *str, t_room *room)
{
	t_room *new;

	get_next_line(fd, &str);
	**data = add_data(**data, data_init(ft_strdup(str)));
	while (str && str[0] == '#')
	{
		free(str);
		get_next_line(fd, &str);
		**data = add_data(**data, data_init(ft_strdup(str)));
	}
	if (!line_check(str))
	{
		printf("ERROR\n");
		exit(1);
	}
	new = room_init(str, room);
	new->is_end = 1;
	free(str);
	room = add_back(new, room);
	return (room);
}

int			my_list_size(t_room *room)
{
	int		i;

	i = 0;
	while (room)
	{
		i++;
		room = room->next;
	}
	return (i - 1);
}
