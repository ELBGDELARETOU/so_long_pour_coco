/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:47 by ademnaouali       #+#    #+#             */
/*   Updated: 2023/11/22 11:01:29 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			c;
	int			number;
	long int	lon;

	lon = n;
	number = ft_countlen(lon) - 1;
	c = ft_countlen(lon);
	i = 0;
	res = (char *)malloc(number + 2);
	if (!res)
		return (NULL);
	if (n < 0)
		res[i++] = '-';
	if (n < 0)
		lon = -lon;
	while (number >= 0 && i < c)
	{
		res[number--] = lon % 10 + '0';
		lon = lon / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}
