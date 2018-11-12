/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:59:03 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/03/16 18:59:05 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	norm_help(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	else
	{
		i--;
		while (str[++i] && str[i] != ' ')
			if (!ft_isdigit(str[i]))
				return (0);
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			return (0);
		i--;
		while (str[++i])
			if (!ft_isdigit(str[i]))
				return (0);
		return (1);
	}
}

int			line_check(char *str)
{
	int		i;

	i = -1;
	if (ft_strcmp("##start", str) && ft_strcmp("##end", str)
		&& !ft_strncmp("##", str, 2))
		return (-1);
	if (!ft_strcmp("##start", str))
		return (2);
	if (!ft_strcmp("##end", str))
		return (3);
	if (str[0] == 'L' || (str[0] == '#' && str[1] != '#'))
		return (-1);
	while (str[++i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]) && !ft_isascii(str[i]))
			return (0);
	}
	if (norm_help(str, i))
		return (1);
	else
		return (0);
}
