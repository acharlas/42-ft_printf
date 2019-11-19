/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:54:38 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/19 13:28:10 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_fill_create(int *len, const char *str, va_list ap)
{
	t_struct	*out;
	
	out = malloc(sizeof(t_struct));
	out = ft_init_struct(out);
	out = ft_fill_struct(out, str, ap);
	out = ft_create_str(out, ap);
	write(1, out->str, out->len);
	*len += out->len;
	free(out->str);
	free(out);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_init_fill_create(&len, str, ap);
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
			len++;
		}
	}
	va_end(ap);
	return (len);
}
