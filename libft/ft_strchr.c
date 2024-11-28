/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:38:09 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:00:32 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	while (str[i])
	{
		if (str[i] == d)
			return ((char *)&str[i]);
		i++;
	}
	if (d == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
