/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:36:23 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/16 18:31:56 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	*shadow_array(int *numbers, int count)

{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < count)
	{
		j = 0;
		while (j < count - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
			}
			j++;
		}
	}
	return (numbers);
}

void	free_doublee_ptr_char(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
	}
	free(ptr);
}

// this function return 0 if the given array sorted and 1 if is not sorted
int	is_sorted(int *numbers, int count)
{
	int	i;

	i = -1;
	while (++i < count - 1)
		if (numbers[i] > numbers[i + 1])
			return (0);
	return (1);
}

void	get_numbers(int *numbers, int count)
{
	int				i;
	t_stack_list	*stack;

	i = -1;
	stack = malloc (sizeof(t_stack_list));
	stack->top_a = -1;
	stack->top_b = -1;
	stack->stack_a = ft_calloc(count, sizeof(int));
	stack->stack_b = ft_calloc(count, sizeof(int));
	if (!stack->stack_a || !stack->stack_a)
		return ;
	while (++i < count)
	{
		stack->stack_a[count - i - 1] = numbers[i];
		stack->top_a++;
	}
	if (count <= 5)
		s_sort(stack, count);
	else if (count > 5)
		b_sort(stack, shadow_array(numbers, count), count);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
}

int	count_argument_after_split(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		i++;
	}
	return (i);
}
