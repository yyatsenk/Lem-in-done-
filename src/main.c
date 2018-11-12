/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:59:35 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/18 17:59:37 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		free_2d(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

int			main(void)
{
	char	*str;
	t_data	*data;
	t_way	*way;
	t_room	*room;
	int		num_of_ants;

	data = data_init(NULL);
	str = NULL;
	if (first_moments(str, data, &num_of_ants) == 0)
		return (0);
	str = line_struct_fill(&room, str, &data);
	if (conect_struct_fill(room, num_of_ants, str, data) == 0)
		return (0);
	way = make_ways(room, room->next, room->next, 0);
	if (!ants_get_way(way, data, room, num_of_ants))
		return (0);
	return (0);
}
