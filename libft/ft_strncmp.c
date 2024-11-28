/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:02:41 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:00:06 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*str1bis;
	unsigned char	*str2bis;
	size_t			i;

	i = 0;
	str1bis = (unsigned char *)str1;
	str2bis = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (n - 1 > i && str1bis[i] && str2bis[i] && str1bis[i] == str2bis[i])
		i++;
	return (str1bis[i] - str2bis[i]);
}
