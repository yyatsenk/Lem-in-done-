/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 09:49:15 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/17 09:49:16 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_rebro	*add_rebro(t_rebro *rebro_to_end, t_rebro *begin)
{
	t_rebro *begin_copy;

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

t_rebro	*rebro_init(int index)
{
	t_rebro *rebro;

	rebro = (t_rebro*)malloc(sizeof(t_rebro));
	rebro->index_of_elem = index;
	rebro->next = NULL;
	return (rebro);
}
