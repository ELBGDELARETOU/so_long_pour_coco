/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:37:32 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:07:26 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char	ft_test(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		c -= 32;
// 	return (c);
// }
/*
#include <stdio.h>

int	main(void)
{
	char *str = ft_strmapi("jeveuxdesmajuscules", &ft_test);
	printf("%s", str);
}*/