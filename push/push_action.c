/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:08:33 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 15:26:13 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

void	pa(t_stack_list *stack, int show)
{
	int	el;

	el = stack->stack_b[stack->top_b];
	stack->top_b--;
	stack->stack_a[++stack->top_a] = el;
	if (show)
		write(1, "pa\n", 3);
}

void	pb(t_stack_list *stack, int show)
{
	int	el;

	el = stack->stack_a[stack->top_a];
	stack->top_a--;
	stack->stack_b[++stack->top_b] = el;
	if (show)
		write(1, "pb\n", 3);
}
