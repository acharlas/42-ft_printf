/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:54:38 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 13:45:43 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putminus(int sign, char *convchar)
{
	if (sign == 1)
		convchar = ft_strjoin(ft_strdup("-"), convchar);
	return (convchar);
}

char	*ckerror(t_struct *out, char *convchar)
{
	if (out->pre == 0 && out->flag & DOT && *convchar == '0')
	{
		free(convchar);
		convchar = ft_strdup("");
	}
	return (convchar);
}

char	*flagzero(t_struct *out, char *convchar, int sign)
{
	if (sign == 1)
		out->width--;
	while (out->width-- > 0)
		convchar = ft_strjoin(ft_strdup("0"), convchar);
	convchar = putminus(sign, convchar);
	return (convchar);
}

char	*flagwidth(t_struct *out, char *convchar, int sign)
{
	if (sign == 1)
		out->width--;
	if (out->flag & MINUS)
		while (out->width-- > 0)
			convchar = ft_strjoin(convchar, ft_strdup(" "));
	else
		while (out->width-- > 0)
			convchar = ft_strjoin(ft_strdup(" "), convchar);
	return (convchar);
}

char	*argnum(t_struct *out, char *convchar)
{
	int	rlsz;
	int	sign;

	sign = 0;
	convchar = ckerror(out, convchar);
	if (*convchar == '-' && (out->flag & DOT || out->flag & ZERO))
	{
		sign = 1;
		convchar = ft_substr(convchar, 1, ft_strlen(convchar) - 1);
	}
	rlsz = ft_strlen(convchar);
	out->pre = out->pre - rlsz < 0 ? 0 : out->pre - rlsz;
	out->width = out->width - (rlsz + out->pre) < 0 ? 0 : \
	out->width - (rlsz + out->pre);
	if (out->flag & ZERO)
	{
		convchar = flagzero(out, convchar, sign);
		return (out->str = convchar);
	}
	while (out->pre-- > 0)
		convchar = ft_strjoin(ft_strdup("0"), convchar);
	convchar = putminus(sign, convchar);
	if (out->width > 0)
		convchar = flagwidth(out, convchar, sign);
	return (out->str = convchar);
}
