/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:24:09 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/14 15:33:22 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

int	max_pos(t_stack_list *stack)
{
	int	i;
	int	pos;

	i = -1;
	pos = 0;
	while (++i <= stack->top_b)
		if (stack->stack_b[i] > stack->stack_b[pos])
			pos = i;
	return (pos);
}

int	suggst_len(int len)
{
	int	number ;

	number = 0;
	if (len <= 100)
		number = 15;
	else if (len > 100)
		number = 35;
	return (number);
}

int	get_index(int *arr, int nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

void	half_sort_stack_b(t_stack_list *stack, int end, int len, int *range)
{
	int	start;

	start = 0;
	while (stack->top_a != -1)
	{
		if (get_index(range, stack->stack_a[stack->top_a], len) >= start
			&& get_index(range, stack->stack_a[stack->top_a], len) <= end)
		{
			pb(stack, 1);
			start++;
			end++;
		}
		else if (get_index(range, stack->stack_a[stack->top_a], len) <= start)
		{
			pb(stack, 1);
			rb(stack, 1);
			start++;
			end++;
		}
		else if (get_index(range, stack->stack_a[stack->top_a], len) > end)
			ra(stack, 1);
	}
}

void	b_sort(t_stack_list *stack, int *range, int len)
{
	int	end;
	int	pos;

	end = suggst_len(len);
	half_sort_stack_b(stack, end, len, range);
	while (stack->top_b > -1 && len >= 0)
	{
		pos = max_pos(stack);
		if (pos == stack->top_b)
		{
			pa(stack, 1);
			len --;
		}
		else if (pos <= len / 2)
			rrb(stack, 1);
		else if (pos > len / 2)
			rb(stack, 1);
	}
}
