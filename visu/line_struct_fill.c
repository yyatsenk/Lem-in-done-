/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_struct_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 09:27:57 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/17 09:27:59 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char	*line_struct_fill(t_room **room, char *str, t_data **data)
{
	int res;

	*room = room_init(str, NULL);
	get_next_line(0, &str);
	*data = add_data(*data, data_init(ft_strdup(str)));
	while ((res = line_check(str)))
	{
		if (res == 2)
			*room = start_set(&data, 0, str, *room);
		else if (res == 3)
			*room = end_set(&data, 0, str, *room);
		else if (res == -1)
		{
			get_next_line(0, &str);
			*data = add_data(*data, data_init(ft_strdup(str)));
			continue ;
		}
		else
			*room = add_back(room_init(str, *room), *room);
		free(str);
		get_next_line(0, &str);
		*data = add_data(*data, data_init(ft_strdup(str)));
	}
	return (str);
}
