/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:54:38 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/12 15:08:34 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_struct *out;

	va_start(ap, str);
	while(*str)
	{
		if(*str == '%' && *str + 1 != '%' && *str + 1 != '\0')
		{
			str += 1;
			out = ft_init_struct(out);
			out = ft_fill_struct(out, str, ap);
			out = ft_create_str(out, ap);
			ft_putstr(out->str);
			while (*str && (*str != 'd' && *str != 'u' && *str != 'i' && *str != 'c' && *str != 's' && *str != 'p' && *str != 'X' && *str != 'x'))
				str++;
		}
		str++;
		if (*str != '\0')
			ft_putchar(*str);
	}
	va_end(ap);
	return (1);
}
