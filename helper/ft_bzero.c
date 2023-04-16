/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:50:49 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/07 12:51:22 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pushswap.h"

void	ft_bzero(void *string, size_t n)
{
	while (n != 0)
	{
		*(char *)string = '\0';
		n--;
		string++;
	}
}
