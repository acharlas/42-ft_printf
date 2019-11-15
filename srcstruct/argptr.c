/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:31:07 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 16:34:25 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argptr(t_struct *out,char *convptr)
{
	int	bufsize;

	bufsize = ft_strlen(convptr);
	out->width = out->width - bufsize < 0 ? 0 : out->width - bufsize;
	if (out->width)
	{
		if (out->flag & MINUS)
			while(out->width--)
				convptr = ft_strjoin(convptr, ft_strdup(" "));
		else
			while(out->width--)
				convptr = ft_strjoin(ft_strdup(" "), convptr);
	}
	return (out->str = convptr);
}