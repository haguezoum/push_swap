/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:29:25 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 15:28:32 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

void	rotate(int *stack, int top)
{
	int	tmp;
	int	i;

	i = top;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	ra(t_stack_list *stack, int show)
{
	rotate(stack->stack_a, stack->top_a);
	if (show)
		write(1, "ra\n", 3);
}

void	rb(t_stack_list *stack, int show)
{
	rotate(stack->stack_b, stack->top_b);
	if (show)
		write(1, "rb\n", 3);
}

void	rr(t_stack_list stack)
{
	ra(&stack, 0);
	rb(&stack, 0);
	write(1, "rr\n", 3);
}
