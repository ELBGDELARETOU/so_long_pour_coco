/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:01:14 by ademnaouali       #+#    #+#             */
/*   Updated: 2023/11/22 11:44:48 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	k;

	i = 0;
	c = 0;
	k = 0;
	if ((!dest || !src) && size == 0)
		return (0);
	while (dest[i])
		i++;
	while (src[k])
		k++;
	if (size <= i)
		k += size;
	else
		k += i;
	while (src[c] && i + 1 < size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = '\0';
	return (k);
}
