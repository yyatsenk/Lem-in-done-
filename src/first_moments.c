/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_moments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:38:34 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 19:38:35 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	help(char **str, int fd, t_data *data, int i)
{
	char	*str_copy;

	while (*str && (*str)[0] == '#' && (str_copy = *str))
	{
		free(*str);
		get_next_line(fd, &str_copy);
		*str = str_copy;
		data = add_data(data, data_init(ft_strdup(*str)));
	}
	if (!(*str) || !(*str)[0] || !ft_isdigit((*str)[0]))
	{
		write(1, "ERROR\n", 6);
		free(*str);
		return (0);
	}
	while ((*str)[++i])
	{
		if (!ft_isdigit((*str)[i]) || (*str)[0] == '0')
		{
			write(1, "ERROR\n", 6);
			free(*str);
			return (0);
		}
	}
	return (1);
}

int			first_moments(char *str, t_data *data, int *num_of_ants)
{
	int		i;
	int		fd;

	fd = 0;
	str = NULL;
	i = get_next_line(fd, &str);
	if (!str || !str[0] || i <= 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	data = add_data(data, data_init(ft_strdup(str)));
	i = -1;
	if (!help(&str, 0, data, -1))
		return (0);
	if (str != NULL && str[0])
	{
		*num_of_ants = ft_atoi(str);
		free(str);
	}
	return (1);
}
