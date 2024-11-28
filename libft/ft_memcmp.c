/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:40:12 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:01:16 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	while (n--)
	{
		if (*s1bis != *s2bis)
			return (*s1bis - *s2bis);
		s1bis++;
		s2bis++;
	}
	return (0);
}
