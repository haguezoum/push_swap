/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:52:11 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 15:30:42 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

void	swap(int *stack, int top)
{
	int	tmp;

	tmp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = tmp;
}

void	sa(t_stack_list *stack, int show)
{
	swap(stack->stack_a, stack->top_a);
	if (show)
		write(1, "sa\n", 3);
}

void	sb(t_stack_list *stack, int show)
{
	swap(stack->stack_b, stack->top_b);
	if (show)
		write(1, "sb\n", 3);
}

void	ss(t_stack_list *stack, int show)
{
	sa(stack, 0);
	sb(stack, 0);
	if (show)
		write(1, "ss\n", 3);
}
