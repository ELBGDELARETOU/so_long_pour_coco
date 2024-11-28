/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:10:35 by anaouali          #+#    #+#             */
/*   Updated: 2023/11/22 11:01:54 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*tab;

	if (num_elements > 0 && element_size > 0 && (SIZE_MAX
			/ num_elements) < element_size)
		return (NULL);
	tab = (void *)malloc(num_elements * element_size);
	if (!tab)
		return (NULL);
	ft_bzero((char *)tab, num_elements * element_size);
	return (tab);
}
