/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:08:50 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 18:07:16 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct    *ft_fill_struct(t_struct *out,const char *str, va_list ap)
{
	while (*str == '-' || *str == '0')	
	{
		if(*str == '-' || *str == '0')
		{
			if (*str == '-')
				out->flag |= MINUS;
			else
				out->flag |= ZERO;
		}
		str++;
	}
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
			out->precision = va_arg(ap, int);
		else
			out->precision = ft_atoi(str);
		while (ft_isdigit(*str) == 1 || *str == '*')
			str++;
	}
	if (*str == 'd' || *str == 'u' || *str == 'i' || *str == 'c' || *str == 's' || *str == 'p'
			|| *str == 'X' || *str == 'x' || *str == '%')
		out->conversion = *str;
	if (out->flag & (DOT | MINUS))
		out->flag &= ~ZERO;
	return(out);
}
