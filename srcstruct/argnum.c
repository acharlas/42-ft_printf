/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:54:38 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 16:49:22 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argnum(t_struct *out, char *convchar)
{
	int	bufsize;
	int	sign;

	sign = 0;
	if (out->precision == 0 && *convchar == '0')
	{
		free(convchar);
		convchar = ft_strdup("");
	}
	if (*convchar == '-')
	{
		sign = 1;
		convchar = ft_substr(convchar, 1, ft_strlen(convchar) - 1);
	}
	bufsize = ft_strlen(convchar);
	out->precision = out->precision - bufsize < 0 ? 0 : out->precision - bufsize;
	out->width = out->width - (bufsize + out->precision) < 0 ? 0 : out->width - (bufsize + out->precision);
	while(out->precision--)
		convchar = ft_strjoin(ft_strdup("0"), convchar);
	if (out->width)
	{
		if (out->flag & MINUS)
			while(out->width--)
				convchar = ft_strjoin(convchar, ft_strdup(" "));
		else
			while(out->width--)
				convchar = ft_strjoin(ft_strdup(" "), convchar);
	}
	if (sign == 1)
		convchar = ft_strjoin(ft_strdup("-"), convchar);
	return (out->str = convchar);
}