/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:15:10 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/09 11:07:57 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litlle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	j = 0;
	ret = (char *)big;
	i = 0;
	if (!litlle[0])
		return ((char *)big);
	if (len == 0 && !big)
		return (NULL);
	while (i < len && big[i])
	{
		while (big[i + j] == litlle[j] && ((i + j) < len))
		{
			j++;
			if (litlle[j] == '\0')
				return (&ret[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
