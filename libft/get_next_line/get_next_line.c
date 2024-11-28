/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:31:49 by anaouali          #+#    #+#             */
/*   Updated: 2023/12/09 05:59:54 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_the_line(t_list *stash)
{
	char	*str;
	int		len;
	int		count;

	if (!stash)
		return (NULL);
	if (!ft_find_end(stash))
		count = BUFFER_SIZE;
	else
		count = ft_find_end(stash);
	len = ((ft_lstsize(stash) * BUFFER_SIZE) - (BUFFER_SIZE - count));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_add_content(stash, str);
	return (str);
}

void	ft_lstadd(t_list **stash, char *buf)
{
	t_list	*new;
	t_list	*last;

	last = ft_lstlast(*stash);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*stash = new;
	else
		last->next = new;
	new->content = buf;
	new->next = NULL;
}

void	ft_stock(t_list **stash, int fd)
{
	int		r;
	char	*buf;

	while (!ft_find_end(*stash))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
		{
			free(buf);
			return ;
		}
		buf[r] = '\0';
		ft_lstadd(stash, buf);
	}
}

void	ft_prepare(t_list **stash)
{
	t_list	*last;
	t_list	*new;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	new = malloc(sizeof(t_list));
	if (!buf || !new)
		return ;
	last = ft_lstlast(*stash);
	i = 0;
	j = 0;
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	while (last->content[i] != '\0' && last->content[++i] && last->content)
		buf[j++] = last->content[i];
	buf[j++] = '\0';
	new->content = buf;
	new->next = NULL;
	ft_clean(stash, new, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	ft_stock(&stash, fd);
	if (!stash)
		return (NULL);
	line = ft_get_the_line(stash);
	if (!stash)
		return (line);
	else
		ft_prepare(&stash);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *str;
// 	int i;

// 	i = 0;
// 	fd = open("bible.txt", O_RDONLY);
// 	while (str != NULL || i == 0)
// 	{
// 		str = get_next_line(fd);
// 		printf("ligne %d : %s\n", i, str);
// 		i++;
// 		free(str);
// 	}
// }