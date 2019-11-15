/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:26:46 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 16:55:12 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	if (!src || !dest)
		return (0);
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && size != 1)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*dst;

	if (!len || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	(void)ft_strlcpy(dst, s + start, len + 1);
	free(s);
	return (dst);
}