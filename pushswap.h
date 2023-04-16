/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:19:49 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 20:52:20 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack_s
{
	int			top_a;
	int			top_b;
	int			*stack_a;
	int			*stack_b;
}	t_stack_list;
void	ft_bzero(void *string, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**split_argv(char **argv, int len);
int		*get_arguments(char **argv, int argc, int *p);
void	error(int status);
void	free_doublee_ptr_char(char **ptr);
void	get_numbers(int *numbers, int count);
void	s_sort(t_stack_list *stack, int count);
void	b_sort(t_stack_list *stack, int *range, int len);
void	sa(t_stack_list *stack, int show);
void	sb(t_stack_list *stack, int show);
void	ss(t_stack_list *stack, int show);
void	ra(t_stack_list *stack, int show);
void	rb(t_stack_list *stack, int show);
void	rr(t_stack_list stack);
void	rra(t_stack_list *stack, int show);
void	rrb(t_stack_list *stack, int show);
void	rrr(t_stack_list stack);
void	pa(t_stack_list *stack, int show);
void	pb(t_stack_list *stack, int show);
int		is_sorted(int *numbers, int count);
int		count_argument_after_split(char **arguments);
#endif