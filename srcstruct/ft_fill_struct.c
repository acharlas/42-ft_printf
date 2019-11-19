/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:08:50 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/18 11:17:49 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*flag_zero_minus(t_struct *out, const char *str)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			out->flag |= MINUS;
		else
			out->flag |= ZERO;
		str++;
	}
	return (str);
}

t_struct		*ft_fill_struct(t_struct *out, const char *str, va_list ap)
{
	str = flag_zero_minus(out, str);
	if (*str == '*')
		out->width = va_arg(ap, int);
	if (ft_isdigit(*str) == 1)
		out->width = ft_atoi(str);
	while (ft_isdigit(*str) == 1 || *str == '*')
		str++;
	if (*str == '.')
	{
		out->flag |= DOT;
		str++;
		if (*str == '*')
			out->pre = va_arg(ap, int);
		else
			out->pre = ft_atoi(str);
		while (ft_isdigit(*str) == 1 || *str == '*')
			str++;
	}
	if (*str == 'd' || *str == 'u' || *str == 'i'
		|| *str == 'c' || *str == 's' || *str == 'p'
			|| *str == 'X' || *str == 'x' || *str == '%')
		out->conversion = *str;
	if (out->flag & (DOT | MINUS))
		out->flag &= ~ZERO;
	return (out);
}
