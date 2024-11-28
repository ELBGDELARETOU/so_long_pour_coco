/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:41:04 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:02:52 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;

	dest1 = dest;
	src1 = src;
	if (dest1 < src1)
	{
		while (n-- > 0)
			*dest1++ = *src1++;
	}
	else if (dest1 > src1)
	{
		dest1 += n;
		src1 += n;
		while (n-- > 0)
			*--dest1 = *--src1;
	}
	return (dest);
}
