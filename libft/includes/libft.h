/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:44:35 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/01 12:13:51 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putendl_red(char *str);
void				ft_putendl_blue(char *str);
void				ft_putendl_cyan(char *str);
void				ft_putendl_green(char *str);
void				ft_putendl_pink(char *str);
void				ft_putendl_yellow(char *str);
void				ft_putstr_blue(char *str);
void				ft_putstr_red(char *str);
void				ft_putstr_cyan(char *str);
void				ft_putstr_green(char *str);
void				ft_putstr_yellow(char *str);
void				ft_putstr_pink(char *str);
int					ft_abs(int nb);
int					ft_nblen(int nb);
void				ft_swap(void *a, void *b);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				*ft_memset(void *b, int c, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_putnbr(int nb);
int					ft_isdigit(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
char				**ft_strsplit(const char *str, char c);
char				*ft_strdup(const char *src);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncat(char *dest, const char *src, int nb);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strstr(const char *str, const char *to_find);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_itoa(int n);
void				ft_print_words_tables(char **tab);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_spr_putstr(char *s1, char *s2, char *s3, char *s4);
void				ft_spr_putendl(char *s1, char *s2, char *s3, char *s4);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strnstr(const char *str, const char *to_find,
		size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_list);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
