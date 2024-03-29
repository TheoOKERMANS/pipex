/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:39:37 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/24 03:50:53 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *b, size_t length);
void	*ft_memcpy(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *memoryBlock, int c, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **list, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putstrtab_fd(char **s, int fd);
void	ft_putinttab_fd(int *tab, size_t size, int fd);
void	ft_put2dinttab_fd(int **tab, size_t h, size_t w, int fd);

//ft_printf
int		printf_hexa_lowcase(unsigned int i);
int		printf_hexa_lowcase_ll(unsigned long long i);
int		printf_hexa_upcase(unsigned int i);
int		ft_putlong_fd(long n, int fd);
int		printf_adress(va_list *param);
int		printf_string(va_list *param);
int		printf_char(va_list *param);
int		printf_int(va_list *param);
int		conversion_manager(char c, va_list *param);
int		ft_printf(const char *str, ...);

//gnl
int		backline_in_str(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);

//hex
int		hex_to_int(char *str);
int		char_hex_to_int(char c);

//tstr
t_str	*new_tstr(char c);
void	add_back_tstr(t_str **list, t_str *new);
void	free_tstr(t_str *tstr);
char	*get_str_from_tstr(t_str *tstr);

//smart split
char	**smart_split(char *str);

#endif