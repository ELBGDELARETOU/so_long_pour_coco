/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:25:14 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/16 18:31:14 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*dest;

	i = 0;
	size = ft_strlen(str);
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	while (size > 0)
	{
		dest[i] = str[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (dest);
}
