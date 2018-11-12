/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_main_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:17:09 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:17:10 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_data		*data_init(char *word)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->word = word;
	data->next = NULL;
	return (data);
}

t_data		*add_data(t_data *data, t_data *to_add)
{
	t_data	*copy;

	copy = data;
	while (data->next)
		data = data->next;
	data->next = to_add;
	return (copy);
}

t_room		*add_back(t_room *room_to_end, t_room *begin)
{
	t_room	*begin_copy;

	begin_copy = begin;
	while (begin->next)
		begin = begin->next;
	begin->next = room_to_end;
	return (begin_copy);
}
