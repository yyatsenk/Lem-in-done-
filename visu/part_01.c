/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:23:01 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/18 16:23:02 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	win_keys_help(t_p *p, int keycode, int *visited)
{
	p->now_room = p->room->next;
	while (p->now_room->index != p->ant_copy->way->elem)
		p->now_room = p->now_room->next;
	while (p->room_copy->index != p->ant_copy->way->next->elem)
		p->room_copy = p->room_copy->next;
	*visited = p->room_copy->is_visited;
	if (p->room_copy->is_visited == 0)
	{
		while (p->room_copy_3->index != p->ant_copy->way->next->elem)
			p->room_copy_3 = p->room_copy_3->next;
		p->now_room->is_visited = 0;
		if (keycode > 0)
			put_ants(&p);
		printf("L%d-%s ", p->ant_copy->num_of_ant, p->room_copy_3->room_name);
		if (p->room_copy->is_end != 1)
			p->room_copy->is_visited = 1;
		else if (!p->ant_copy->way->next->next)
			p->got_end++;
		if (p->ant_copy->way->next)
			p->ant_copy->way = p->ant_copy->way->next;
	}
}

static int	last(t_p *p, int keycode, int visited)
{
	while (p->got_end != p->num_of_ants)
	{
		while (p->ant_copy)
		{
			p->room_copy = p->room->next;
			p->room_copy_3 = p->room->next;
			if (p->ant_copy->way->next == NULL)
			{
				p->ant_copy = p->ant_copy->next;
				continue ;
			}
			win_keys_help(p, keycode, &visited);
			if (p->ant_copy)
			{
				p->ant_copy = p->ant_copy->next;
				if (visited == 0)
					return (0);
			}
		}
		p->ant_copy = p->ant;
		printf("\n");
	}
	return (1);
}

int			win_keys(int keycode, void *param)
{
	t_p		*p;
	int		visited;

	p = (t_p*)param;
	if (p->got_end == p->num_of_ants || keycode == 53)
		exit(EXIT_SUCCESS);
	if (!last(p, keycode, visited))
		return (0);
	return (0);
}

int			bonus(int argv, char **argc, int *teplo)
{
	void	*mlx_ptr_2;
	void	*win_ptr_2;

	if (argv != 2)
	{
		printf("Usage:\n-normal\tas usual\n-joke\t");
		printf("bayan\n-teplo\tnemnoho solntsa\n");
		return (0);
	}
	if (!ft_strcmp(argc[1], "-joke"))
	{
		mlx_ptr_2 = mlx_init();
		win_ptr_2 = mlx_new_window(mlx_ptr_2, 400, 400, "Bad joke");
		mlx_string_put(mlx_ptr_2, win_ptr_2, 100,\
			180, GREEN, "Joke doesn\'t want you :)\n");
		mlx_string_put(mlx_ptr_2, win_ptr_2, 100,\
			210, GREEN, "Have a good day!\n");
		mlx_loop(mlx_ptr_2);
		return (0);
	}
	else if (!ft_strcmp(argc[1], "-teplo"))
		*teplo = 1;
	else if (!ft_strcmp(argc[1], "-normal"))
		*teplo = 0;
	return (1);
}
