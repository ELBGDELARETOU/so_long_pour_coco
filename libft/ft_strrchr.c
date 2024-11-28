/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:07:08 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:56 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == d)
			return (str + i);
		i--;
	}
	return (NULL);
}
