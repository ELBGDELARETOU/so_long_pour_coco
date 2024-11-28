/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:14:14 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/16 12:32:00 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;
	char		d;

	d = (char)c;
	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == d)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
