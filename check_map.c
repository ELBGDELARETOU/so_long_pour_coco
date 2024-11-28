/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:49:49 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/27 12:25:57 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map, int number_of_lines, int len_of_lines)
{
	int	i;

	i = 0;
	while (i != len_of_lines)
	{
		if (map[0][i] != '1' || map[number_of_lines][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i != number_of_lines)
	{
		if (map[i][0] != '1' || map[i][len_of_lines - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_map_letters(char *map, t_slg *slg)
{
	if (map[slg->m_i] == 'E')
		slg->e_count++;
	if (map[slg->m_i] == 'P')
		slg->p_count++;
	if (map[slg->m_i] == 'C')
		slg->c_count += 1;
	if ((map[slg->m_i] != 'C' && map[slg->m_i] != 'E' && map[slg->m_i] != 'P'
			&& map[slg->m_i] != '0' && map[slg->m_i] != '1'
			&& map[slg->m_i] != '\n') || map[0] == '\n')
		return (-1);
	return (0);
}

int	check_map(char *map, t_slg *slg)
{
	while (map[slg->m_i] != '\0')
	{
		if (map[slg->m_i] == '\n' && (ft_strlen_of_one_line(map)) != slg->m_c)
			return (-1);
		if (map[slg->m_i] == '\n')
		{
			slg->m_c = -1;
			slg->backslash_n_count++;
		}
		if (map[slg->m_i] == '\n' && (map[slg->m_i + 1] == '\n' || map[slg->m_i
					+ 1] == '\0'))
			return (-1);
		if (check_map_letters(map, slg) == -1)
			return (-1);
		slg->m_i++;
		slg->m_c++;
	}
	if (map[slg->m_i] == '\0' && (ft_strlen_of_one_line(map)) != slg->m_c)
		return (-1);
	if (slg->e_count != 1 || slg->p_count != 1 || slg->backslash_n_count > 13
		|| slg->backslash_n_count < 2)
		return (-1);
	return (0);
}

void	path_flood(t_slg *slg, int x, int y)
{
	if (slg->rectangle_copy[y][x] == '0' || slg->rectangle_copy[y][x] == 'C'
		|| slg->rectangle_copy[y][x] == 'P')
	{
		slg->rectangle_copy[y][x] = '1';
		path_flood(slg, x - 1, y);
		path_flood(slg, x, y - 1);
		path_flood(slg, x + 1, y);
		path_flood(slg, x, y + 1);
	}
	if (slg->rectangle_copy[y][x] == 'E')
	{
		slg->rectangle_copy[y][x] = '1';
		return ;
	}
}

int	check_rectangle(char *map, t_slg *slg)
{
	if (!count_line(map))
		return (-1);
	slg->number_of_lines = count_line(map);
	slg->len_of_lines = ft_strlen_of_one_line(map);
	slg->rectangle = ft_split(map, '\n');
	slg->rectangle_copy = ft_split(map, '\n');
	free(map);
	return (check_walls(slg->rectangle, slg->number_of_lines,
			slg->len_of_lines));
}
