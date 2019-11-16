/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:13:54 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 12:22:59 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dig_cnt(long c, int base)
{
	int	i;

	i = 0;
	while (c)
	{
		c /= base;
		i++;
	}
	return (i);
}

static char	*set_base_string(int n_base)
{
	char	*base;

	if (n_base == 10)
		base = ft_strdup("0123456789");
	else if (n_base == 16)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = NULL;
	return (base);
}

int			checkerror(long long c, const char *base)
{
	if (c == 0)
	{
		free((char *)base);
		return (1);
	}
	return (0);
}

char		*ft_itoa_base(long long c, int n_base)
{
	int			i;
	int			neg;
	char		*out;
	const char	*base = set_base_string(n_base);

	if (checkerror(c, base))
		return (ft_strdup("0"));
	i = dig_cnt(c, n_base) + (c < 0 ? 1 : 0);
	neg = (c < 0) ? -1 : 1;
	c = c * neg;
	if (!(out = malloc(sizeof(char) * i + 1)))
		return (NULL);
	out[i--] = '\0';
	while (c)
	{
		out[i--] = base[c % n_base];
		c /= n_base;
	}
	if (neg < 0)
		out[i--] = '-';
	i++;
	free((char *)base);
	return (out + i);
}
