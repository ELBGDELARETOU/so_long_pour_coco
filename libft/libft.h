/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:35:33 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/23 16:57:30 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line/get_next_line.h"
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				ft_bzero(char *str, size_t n);
void				*ft_calloc(size_t num_elements, size_t element_size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *ptr, int value, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
const char			*ft_strrchr(const char *str, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				**ft_split(char const *str, char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *str);

#endif
