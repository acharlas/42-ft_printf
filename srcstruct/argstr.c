/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:46:44 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/19 11:55:28 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argstr(t_struct *out, char *convstr)
{
	if (convstr == NULL)
	{
		free(convstr);
		convstr = ft_strdup("(null)");
	}
	if (out->flag & DOT)
		convstr = ft_strndup(convstr, out->pre);
	out->len = ft_strlen(convstr);
	out->width = out->width - out->len < 0 ? 0 : out->width - out->len;
	if (out->width)
	{
		if (out->flag & MINUS)
			while (out->width-- > 0)
			{
				out->len++;
				convstr = ft_strjoin(convstr, ft_strdup(" "));
			}
		else
			while (out->width-- > 0)
			{
				out->len++;
				convstr = ft_strjoin(ft_strdup(" "), convstr);
			}
	}
	return (out->str = convstr);
}
