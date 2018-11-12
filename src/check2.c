/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:04:27 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:04:28 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			check_ignore(t_way *way)
{
	int		is_way;

	is_way = 0;
	while (way)
	{
		if (way->ignore == 0)
			is_way++;
		way = way->next;
	}
	if (is_way == 0)
		return (0);
	else
		return (1);
}

int			check_end_start(t_room *room)
{
	t_room	*begin;
	int		end;
	int		start;

	end = 0;
	start = 0;
	begin = room;
	while (room)
	{
		if (room->is_start)
			start++;
		if (room->is_end)
			end++;
		room = room->next;
	}
	if (start != 1 || end != 1)
		return (1);
	else
		return (0);
}

static int	dick(char *str, int i)
{
	if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else
		return (1);
}

int			connection_valid_check(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	if (!str[0] || str[0] == '\n')
		return (3);
	if (!ft_strncmp("#", str, 1))
		return (2);
	while (str[++i] && str[i] != '-')
	{
		if (!dick(str, i))
			return (0);
	}
	if (str[i] == '\0')
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	while (str[++i])
	{
		if (!dick(str, i))
			return (0);
	}
	return (1);
}
