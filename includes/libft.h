/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 20:16:49 by rgilles           #+#    #+#             */
/*   Updated: 2020/03/23 20:16:51 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_printf
{
	va_list			args;
	unsigned int	i;
	unsigned int	nbwritten;
	char			minus;
	char			zero;
	int				field_len;
	int				prec;
	char			conv;
	int				is_l;
}				t_printf;

typedef struct	s_number
{
	unsigned long long	number;
	int					nbd;
}				t_nb;

void			init(t_printf *myprintf);
void			get_parsing_params(const char *to_parse, t_printf *myptf);
int				complete_field_len(t_printf *myprintf, int nbwritten);

int				print_c(t_printf *myprintf, char forcechar);
int				print_s(t_printf *myprintf);
int				print_nb_base(t_printf *myptf, char *cs, int sgd, int lon);

int				display(t_printf *myprintf);
int				ft_printf(const char *to_parse, ...);

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isspace(int c);

char			*ft_strchr(const char *str, int c);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strrchr(const char *str, int c);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, int size, int newsize);
char			*ft_strdup(const char *src);

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_nbdigits_base(unsigned long long int nb, int base);

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_uns_fd(unsigned long long int nb, int fd);
void			ft_putnbr_uns_base_fd(unsigned long long int u, int f, char *c);
void			ft_putstr_fd(char *s, int fd);

void			ft_putchar(char c);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putnbr_uns(unsigned long long int nb);
void			ft_putnbr_uns_base(unsigned long long int nb, char *charset);
void			ft_putstr(char *s);

void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

double			ft_sqrt(double nb);

int				get_next_line(int fd, char **line);

#endif
