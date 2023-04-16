/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:28 by haguezou          #+#    #+#             */
/*   Updated: 2023/04/16 18:28:14 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	duplicate(int *number, int len)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (number[i] == number[j])
			{
				k++;
				return (k);
			}
			j++;
		}
	}
	return (0);
}

long	ft_atoi_min_max_int(const char *str)
{
	long	res;
	size_t	i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if ((res > 2147483647) && sign == 1)
			error(1);
		if ((res > 2147483648) && sign == -1)
			error(1);
		i++;
	}
	return (res * sign);
}

char	**split_argv(char **argv, int len)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**numbers;

	i = 0;
	str = ft_strdup("");
	while (++i < len)
	{
		tmp = ft_strjoin(str, argv[i]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
	}
	numbers = ft_split(str, ' ');
	free(str);
	return (numbers);
}

int	check_degit(char **arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i])
	{
		j = -1;
		if (arg[i][0] == '+' || arg[i][0] == '-')
			j++;
		if (!ft_isdigit(arg[i][j + 1]))
			error(1);
		while (arg[i][++j])
		{
			if (!ft_isdigit(arg[i][j]))
				error(1);
		}
	}
	return (1);
}

int	*get_arguments(char **argv, int argc, int *p)
{
	char	**arguments;
	int		i;
	int		*numbers;

	numbers = NULL;
	i = -1;
	arguments = split_argv(argv, argc);
	if (check_degit(arguments))
	{
		numbers = malloc(count_argument_after_split(arguments) * sizeof(int));
		if (!numbers)
			return (NULL);
		while (arguments[++i])
			numbers[i] = ft_atoi_min_max_int(arguments[i]);
		*p = i;
	}
	if (i < 1 || duplicate(numbers, i))
	{
		free_doublee_ptr_char(arguments);
		free(numbers);
		error(1);
	}
	free_doublee_ptr_char(arguments);
	return (numbers);
}
