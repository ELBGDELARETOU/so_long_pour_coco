/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:12:10 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/21 13:10:23 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tab)
		return (NULL);
	while (s1[s])
	{
		tab[s] = s1[s];
		s++;
	}
	while (s2[i])
	{
		tab[s] = s2[i];
		i++;
		s++;
	}
	tab[s] = '\0';
	return (tab);
}
// int	ft_strlen1(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char *tab;
// 	int i;

// 	i = 0;
// 	if (!s1)
// 		s1 = ft_strdup("");
// 	tab = malloc(ft_strlen1(s1) + 2);
// 	if (!tab)
// 		return (NULL);
// 	while (i < ft_strlen1(s1))
// 	{
// 		tab[i] = s1[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		tab[i] = s2[i];
// 		i++;
// 	}
// 	tab[i] = 0;
// 	free(s1);
// 	free(s2);
// 	return (tab);
// }