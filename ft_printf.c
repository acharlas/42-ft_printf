/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:54:38 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 12:11:25 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_init_fill_create(t_struct *out, const char *str, va_list ap)
{
	out = malloc(sizeof(t_struct));
	out = ft_init_struct(out);
	out = ft_fill_struct(out, str, ap);
	out = ft_create_str(out, ap);
	write(1, out->str, ft_strlen(out->str));
	free(out->str);
	free(out);
	return (out);
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	*out;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += 1;
			out = ft_init_fill_create(out, str, ap);
			while (*str && (*str != 'd' && *str != 'u' && *str != 'i' &&
					*str != 'c' && *str != 's' && *str != 'p' &&
					*str != 'X' && *str != 'x' && *str != '%'))
				str++;
			str++;
		}
		else if (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
	va_end(ap);
	return (1);
}
