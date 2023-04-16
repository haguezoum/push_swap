/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:12:37 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/16 18:27:10 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

int	min_pos(t_stack_list *stack)
{
	int	i;
	int	pos;

	i = -1;
	pos = 0;
	while (++i <= stack->top_a)
		if (stack->stack_a[i] < stack->stack_a[pos])
			pos = i;
	return (pos);
}

void	sort_more_case(t_stack_list *stack)
{
	if (stack->stack_a[2] > stack->stack_a[1]
		&& stack->stack_a[2] > stack->stack_a[0]
		&& stack->stack_a[1] < stack->stack_a[0])
		ra(stack, 1);
	else if (stack->stack_a[2] < stack->stack_a[1]
		&& stack->stack_a[2] < stack->stack_a[0]
		&& stack->stack_a[1] > stack->stack_a[0])
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (stack->stack_a[2] < stack->stack_a[1]
		&& stack->stack_a[2] > stack->stack_a[0]
		&& stack->stack_a[0] < stack->stack_a[1])
		rra(stack, 1);
}

void	sort_3(t_stack_list *stack)
{
	if (stack->stack_a[2] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[0]
		&& stack->stack_a[2] < stack->stack_a[0])
		sa(stack, 1);
	else if (stack->stack_a[2] > stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[0]
		&& stack->stack_a[2] > stack->stack_a[0])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	sort_more_case(stack);
}

void	sort_5(t_stack_list *stack, int count)
{
	int	pos;
	int	len;

	len = count;
	while (len != 3)
	{
		pos = min_pos(stack);
		if (pos <= len / 2)
			rra(stack, 1);
		else if (pos == stack->top_a)
		{
			pb(stack, 1);
			len--;
		}
		else
			ra(stack, 1);
	}
	sort_3(stack);
	pa(stack, 1);
	if (count > 4)
		pa(stack, 1);
}

void	s_sort(t_stack_list *stack, int count)
{
	if (count == 2)
		sa(stack, 1);
	else if (count == 3)
	{
		sort_3(stack);
	}
	else if (count <= 5)
		sort_5(stack, count);
}
