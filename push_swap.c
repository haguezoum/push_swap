/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:46:55 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/16 18:34:29 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	error(int status)
{
	write(2, "Error\n", 6);
	if (status)
		exit(1);
	else
		exit(0);
}

void	check_space(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				break ;
			j++;
		}
		if (argv[i][j] == '\0')
			error(1);
	}
}

int	main(int ac, char *av[])
{
	int	count;
	int	*numbers;

	if (ac < 2)
		exit(0);
	else
	{
		check_space(av);
		numbers = get_arguments(av, ac, &count);
		if (is_sorted(numbers, count))
		{
			free(numbers);
			exit(0);
		}
		get_numbers(numbers, count);
		free (numbers);
	}
	return (0);
}
