/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:42:10 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/12 15:05:27 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_len(long int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n == 0)
		size++;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		lim;
	long	nb;

	nb = (long)n;
	size = nb_len(n);
	lim = 0;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
		lim = 1;
	}
	while (size > lim)
	{
		size--;
		res[size] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}
