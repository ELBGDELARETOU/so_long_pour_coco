/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:58:34 by anaouali          #+#    #+#             */
/*   Updated: 2023/12/09 05:59:35 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_find_end(t_list *stash)
{
	int	i;

	if (!stash)
		return (0);
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
				return (++i);
			i++;
		}
		stash = stash->next;
	}
	return (0);
}

void	ft_add_content(t_list *stash, char *line)
{
	int	index;
	int	c;

	if (!stash)
		return ;
	c = 0;
	while (stash)
	{
		index = 0;
		while (stash->content[index])
		{
			if (stash->content[index] == '\n')
			{
				line[c] = '\n';
				line[++c] = '\0';
				return ;
			}
			line[c++] = stash->content[index++];
		}
		stash = stash->next;
	}
	line[c] = '\0';
}

void	ft_clean(t_list **stash, t_list *new, char *buf)
{
	t_list	*tmp;

	if (!stash)
		return ;
	while (*stash)
	{
		tmp = (*stash)->next;
		free((*stash)->content);
		free(*stash);
		*stash = tmp;
	}
	*stash = NULL;
	if (new->content[0])
		*stash = new;
	else
	{
		free(buf);
		free(new);
	}
}
