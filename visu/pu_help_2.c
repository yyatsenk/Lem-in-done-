/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_help_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:39:42 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/19 11:39:44 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	put_help_2(t_cc *c, t_p **p)
{
	c->x0 = (*p)->now_room->coords.x * (*p)->kof;
	c->x1 = (*p)->room_copy_3->coords.x * (*p)->kof;
	c->y0 = (*p)->now_room->coords.y * (*p)->kof;
	c->y1 = (*p)->room_copy_3->coords.y * (*p)->kof;
	if ((*p)->now_room->is_start != 1)
	{
		mlx_clear_window((*p)->mlx_ptr, (*p)->win_ptr);
		build_map((*p)->room->next, &(*p)->mlx_ptr, &(*p)->win_ptr, (*p)->kof);
	}
}
