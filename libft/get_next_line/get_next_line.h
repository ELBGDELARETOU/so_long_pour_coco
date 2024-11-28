/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:58:20 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/15 15:09:05 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);

int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
int					ft_find_end(t_list *stash);
void				ft_add_content(t_list *stash, char *line);
void				ft_clean(t_list **stash, t_list *new, char *buf);
char				*ft_get_the_line(t_list *stash);
void				ft_lstadd(t_list **stash, char *buf);
void				ft_stock(t_list **stash, int fd);
void				ft_prepare(t_list **stash);
char				*get_next_line(int fd);

#endif