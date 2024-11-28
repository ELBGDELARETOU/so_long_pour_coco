/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:22:44 by anaouali          #+#    #+#             */
/*   Updated: 2024/04/10 12:04:27 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(char *map, t_slg *slg)
{
	if (check_map(map, slg) == -1)
	{
		free(map);
		close(slg->fd);
		ft_putstr_fd("Error\nInvalid map... Retry !\n", 2);
		return (0);
	}
	if (check_rectangle(map, slg) == -1)
	{
		ft_putstr_fd("Error\nInvalid map... Retry !\n", 2);
		closer(slg);
	}
	return (1);
}

void	handle_no_map(char *map)
{
	ft_putstr_fd("Error\nWrong map sorry... Retry !\n", 2);
	free(map);
}

int	check(t_slg *slg, char *argv)
{
	slg->fd = 0;
	slg->fd = open(argv, O_RDONLY);
	slg->line = get_next_line(slg->fd);
	slg->tmp = "";
	slg->map = ft_strjoin(slg->tmp, slg->line);
	free(slg->line);
	if (!slg->map)
		return (handle_no_map(slg->map), -1);
	while (slg->line)
	{
		slg->line = get_next_line(slg->fd);
		slg->tmp = slg->map;
		if (slg->line == NULL)
		{
			free(slg->line);
			break ;
		}
		slg->map = ft_strjoin(slg->tmp, slg->line);
		free(slg->tmp);
		free(slg->line);
	}
	if (!check_all(slg->map, slg))
		return (-1);
	return (0);
}
