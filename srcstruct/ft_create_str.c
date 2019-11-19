/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:00:05 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/19 15:45:00 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conversion_char(va_list ap)
{
	char *convchar;

	convchar = malloc(sizeof(char) * 2);
	convchar[0] = va_arg(ap, int);
	convchar[1] = '\0';
	return (convchar);
}

char		*ft_conversion(t_struct *out, va_list ap)
{
	char	*convchar;

	convchar = NULL;
	if (out->conversion == 'c')
		convchar = conversion_char(ap);
	else if (out->conversion == 'd')
		convchar = ft_itoa_base(va_arg(ap, int), 10);
	else if (out->conversion == 's')
		convchar = ft_strdup(va_arg(ap, char *));
	else if (out->conversion == 'u')
		convchar = ft_itoa_base((unsigned int)va_arg(ap, unsigned int), 10);
	else if (out->conversion == 'i')
		convchar = ft_itoa_base((signed int)va_arg(ap, signed int), 10);
	else if (out->conversion == 'p')
		convchar = ft_itoa_base(va_arg(ap, unsigned long), 16);
	else if (out->conversion == 'x')
		convchar = ft_itoa_base(va_arg(ap, unsigned int), 16);
	else if (out->conversion == 'X')
		convchar = ft_itoa_base(va_arg(ap, unsigned int), 16);
	else if (out->conversion == '%')
		convchar = ft_strdup("%");
	else
		(void)va_arg(ap, void *);
	return (convchar);
}

t_struct	*ft_create_str(t_struct *out, va_list ap)
{
	char	*convchar;

	convchar = ft_conversion(out, ap);
	if (out->conversion == 'x' || out->conversion == 'p')
		convchar = ft_tolower(convchar);
	if (out->conversion == 'p')
		convchar = ft_strjoin(ft_strdup("0x"), convchar);
	if (out->conversion == 'd' || out->conversion == 'u' || out->conversion \
		== 'i' || out->conversion == 'X' || out->conversion == 'x')
		out->str = argnum(out, convchar);
	if (out->conversion == 's')
		out->str = argstr(out, convchar);
	if (out->conversion == 'p' || out->conversion == 'c' ||
		out->conversion == '%')
		out->str = argptr(out, convchar);
	return (out);
}
