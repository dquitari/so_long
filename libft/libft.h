/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:35:17 by dquitari          #+#    #+#             */
/*   Updated: 2023/09/11 09:35:19 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


typedef struct s_list
{
	struct s_list	*next;
	int			x;
	int			y;
	int			index;
	int			landmark;
}	t_walk_list;

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*get_next_line(int fd);
char		*ft_itoa(int n);
char		*ft_strjoin(char *stash, char *buffer);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(const char *str);
t_walk_list	*ft_lstnew(int content);
t_walk_list	*ft_lstlast(t_walk_list *lst);
void		ft_lstadd_back(t_walk_list **lst, t_walk_list *new);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_lstsize(t_walk_list *lst);
int			ft_printf(const char *str, ...);
int			ft_test_printf(const char *str, ...);
int			ft_abs(int n);
int			ft_test_print_char(char c);
int			ft_print_char(char c);
int			ft_print_hex(unsigned int n, const char format);
int			ft_print_nbr(int n);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_str(char *str);
int			ft_print_unbr(unsigned int unbr);

#endif
