/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:26:28 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/18 16:54:25 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	build_help(t_cc *c, t_room *r_c, t_room *r_c_2, int k)
{
	c->x0 = r_c->coords.x * k;
	c->x1 = r_c_2->coords.x * k;
	c->y0 = r_c->coords.y * k;
	c->y1 = r_c_2->coords.y * k;
}

void		build_map(t_room *room, void **m_p, void **w_p, int k)
{
	t_room	*r_c;
	t_room	*r_c_2;
	t_rebro	*down_copy;
	int		cof;
	t_cc	c;

	r_c = room;
	r_c_2 = room;
	teplo_cof(m_p, w_p, k, &cof);
	while (r_c)
	{
		down_copy = r_c->down;
		while (r_c->down && (r_c_2 = room))
		{
			while (r_c_2->index != r_c->down->index_of_elem)
				r_c_2 = r_c_2->next;
			build_help(&c, r_c, r_c_2, k);
			make_line(*m_p, *w_p, c, r_c_2->room_name);
			r_c->down = r_c->down->next;
		}
		r_c->down = down_copy;
		r_c = r_c->next;
	}
}

static void	put_help(t_cc *c, int *conx, int *cony)
{
	if (c->y1 == c->y0 && (c->y0 += 1))
		*cony = 0;
	if (c->x1 == c->x0 && (c->x0 += 1))
		*conx = 0;
}

void		put_ants(t_p **p)
{
	t_cc	c;
	int		conx;
	int		cony;

	put_help_2(&c, p);
	conx = ft_abs((c.x1 - c.x0) / 2);
	cony = ft_abs((c.y1 - c.y0) / 2);
	put_help(&c, &conx, &cony);
	if (c.y0 < c.y1 && c.x0 < c.x1)
		mlx_string_put((*p)->mlx_ptr, (*p)->win_ptr, c.x0 + conx,\
			c.y0 + cony, PINK, ft_itoa_l((*p)->ant_copy->num_of_ant));
	else if (c.y0 > c.y1 && c.x0 < c.x1)
		mlx_string_put((*p)->mlx_ptr, (*p)->win_ptr, c.x0 + conx, c.y0 - cony,\
			PINK, ft_itoa_l((*p)->ant_copy->num_of_ant));
	else if (c.y0 > c.y1 && c.x0 > c.x1)
		mlx_string_put((*p)->mlx_ptr, (*p)->win_ptr, c.x0 - conx, c.y0 - cony,\
			PINK, ft_itoa_l((*p)->ant_copy->num_of_ant));
	else if (c.y0 < c.y1 && c.x0 > c.x1)
		mlx_string_put((*p)->mlx_ptr, (*p)->win_ptr, c.x0 - conx, c.y0 + cony,\
			PINK, ft_itoa_l((*p)->ant_copy->num_of_ant));
}

t_p			*p_init(int num_of_ants, t_ant *ant, t_room *room, t_room *now_room)
{
	t_p		*p;

	p = (t_p*)malloc(sizeof(t_p));
	p->got_end = 0;
	p->num_of_ants = num_of_ants;
	p->ant = ant;
	p->ant_copy = ant;
	p->room = room;
	p->room_copy = room->next;
	p->room_copy_3 = room->next;
	p->now_room = now_room;
	p->teplo = g_teplo;
	return (p);
}
