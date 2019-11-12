/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:43:17 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/12 15:06:01 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	if (!s1 || !s2)
		return (0);
	if (!(tab = (char*)malloc(sizeof(char) *
					((ft_strlen(s1) + ft_strlen((s2)) + 1)))))
		return (0);
	while (s1[i])
		tab[count++] = s1[i++];
	while (s2[j])
		tab[count++] = s2[j++];
	tab[count] = '\0';
	return (tab);
}
