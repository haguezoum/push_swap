/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:21:12 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 15:27:08 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

void	r_rotate(int *stack, int top)
{
	int	tmp ;
	int	i;

	i = -1;
	tmp = stack[0];
	while (++i < top)
		stack[i] = stack[i + 1];
	stack[i] = tmp;
}

void	rra(t_stack_list *stack, int show)
{
	r_rotate(stack->stack_a, stack->top_a);
	if (show)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_list *stack, int show)
{
	r_rotate(stack->stack_b, stack->top_b);
	if (show)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_list stack)
{
	rra(&stack, 0);
	rrb(&stack, 0);
	write(1, "rrr\n", 4);
}
