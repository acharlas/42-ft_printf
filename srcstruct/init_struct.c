/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:27:18 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/16 13:44:01 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_init_struct(t_struct *out)
{
	out->str = NULL;
	out->pre = 0;
	out->width = 0;
	out->conversion = '\0';
	out->flag = 0;
	return (out);
}
