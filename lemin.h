/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:56:43 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/19 10:56:44 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include "./libft/libft.h"
# include "lemin.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_b
{
	char			*word;
	struct s_b		*next;
}					t_data;

typedef struct		s_c
{
	int				index_of_elem;
	struct s_c		*next;
}					t_rebro;

typedef struct		s_d
{
	int				x;
	int				y;
}					t_coords;

typedef struct		s_e
{
	char			*room_name;
	int				index;
	t_coords		coords;
	int				is_start;
	int				is_end;
	int				is_visited;
	t_rebro			*down;
	struct s_e		*next;
}					t_room;

typedef struct		s_g
{
	int				elem;
	int				distance;
	struct s_g		*next;
	struct s_g		*prev;
}					t_way_down;

typedef struct		s_i
{
	int				num_of_way;
	int				parent;
	int				weight;
	int				ignore;
	struct s_i		*next;
	t_way_down		*down;
}					t_way;
typedef struct		s_ant
{
	int				num_of_ant;
	t_way_down		*way;
	struct s_ant	*next;
}					t_ant;
int					line_check(char *str);
int					connection_valid_check(char *str);
int					check_end_start(t_room *room);
int					check_ignore(t_way *way);
int					my_list_size(t_room *room);
t_room				*end_set(t_data ***data, int fd, char *str, t_room *room);
t_room				*start_set(t_data ***data, int fd, char *str, t_room *room);
t_room				*room_init(char *str, t_room *room_1);
t_data				*data_init(char *word);
t_data				*add_data(t_data *data, t_data *to_add);
t_room				*add_back(t_room *room_to_end, t_room *begin);
int					list_size_down(t_way_down *list);
t_way_down			*w_down_copy(t_way_down *list);
t_way_down			*way_down_init(int index, int distance);
t_way_down			*add_way_down(t_way_down *rebro_to_end, t_way_down *begin);
int					shortest(t_way *way);
t_way				*way_sort(t_way *way, t_room *room);
t_way				*add_way(t_way *rebro_to_end, t_way *begin);
t_way				*way_init(int index, int parent);
t_ant				*ant_add(t_ant *rebro_to_end, t_ant *begin);
t_ant				*ant_init(int num_of_ant);
void				room_free(t_room *room);
void				free_ant(t_ant **ant);
void				data_free(t_data *data);
int					first_moments(char *str, t_data *data, int *num_of_ants);
char				*line_struct_fill(t_room **room, char *str, t_data **data);
t_rebro				*add_rebro(t_rebro *rebro_to_end, t_rebro *begin);
t_rebro				*rebro_init(int index);
int					conect_struct_fill(t_room *room, int num_of_ants,\
	char *str, t_data *data);
t_way				*make_ways(t_room *room, t_room *room_copy,\
	t_room *room_copy_2, int count);
int					ants_get_way(t_way *way, t_data *data, t_room *room,\
	int num_of_ants);
void				free_2d(char **str);
#endif
