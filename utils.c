/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:24:55 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/27 12:25:47 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_of_one_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	count_line(char *map)
{
	int	i;
	int	new_line;

	i = 0;
	new_line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (map[i + 1] == '\n')
				return (0);
			new_line++;
		}
		i++;
	}
	return (new_line);
}
