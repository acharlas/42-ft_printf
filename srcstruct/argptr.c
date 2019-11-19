/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:31:07 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/19 16:36:58 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_special_join(char *s1, char *s2, int len1, int len2)
{
	char	*out;

	out = malloc(sizeof(char) * len1 + len2);
	ft_memcpy(out, s1, len1);
	ft_memcpy(out + len1, s2, len2);
	free(s1);
	free(s2);
	return (out);
}

char	*flag_zero(t_struct *out, char *convptr)
{
	if (out->flag & MINUS)
		while (out->width-- > 0)
		{
			out->len++;
			convptr = ft_strjoin(convptr, ft_strdup("0"));
		}
	else
		while (out->width-- > 0)
		{
			out->len++;
			convptr = ft_strjoin(ft_strdup("0"), convptr);
		}
	return (convptr);
}

char	*argptr(t_struct *out, char *convptr)
{
	if (out->conversion == 'c' && convptr[0] == '\0')
		out->len = 1;
	else
		out->len = ft_strlen(convptr);
	out->width = out->width - out->len < 0 ? 0 : out->width - out->len;
	if (out->flag & ZERO)
		convptr = flag_zero(out, convptr);
	if (out->width > 0)
	{
		if (out->flag & MINUS)
			while (out->width-- > 0)
			{
				convptr = ft_special_join(convptr, ft_strdup(" "), out->len, 1);
				out->len++;
			}
		else
			while (out->width-- > 0)
			{
				convptr = ft_special_join(ft_strdup(" "), convptr, 1, out->len);
				out->len++;
			}
	}
	return (out->str = convptr);
}
