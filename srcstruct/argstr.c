/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:46:44 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 18:55:18 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argstr(t_struct *out,char *convstr)
{
	int	bufsize;

	if (convstr == NULL)
	{
		free(convstr);
		convstr = ft_strdup("(null)");
	}
	if (out->flag & DOT)
		convstr = ft_strndup(convstr, out->precision);
	bufsize = ft_strlen(convstr);
	out->width = out->width - bufsize < 0 ? 0 : out->width - bufsize;
	if (out->width)
	{
		if (out->flag & MINUS)
			while(out->width--)
				convstr = ft_strjoin(convstr, ft_strdup(" "));
		else
			while(out->width--)
				convstr = ft_strjoin(ft_strdup(" "), convstr);
	}
	return (out->str = convstr);
}