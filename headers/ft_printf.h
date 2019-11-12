/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:57:16 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/12 15:05:45 by acharlas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define ZERO 0x1
# define MINUS 0x2
# define DOT 0x4

typedef struct	s_struct
{
	char	*str;
	int		precision;
	int		width;
	char	conversion;
	int		flag : 3;

}				t_struct;

t_struct    *ft_init_struct(t_struct *out);
t_struct    *ft_fill_struct(t_struct *out,const char *str, va_list ap);
t_struct    *ft_create_str(t_struct *out, va_list ap);
char	*ft_strdup(char *s);
char		*ft_itoa_base(long long c, int n_base);
void	ft_putchar(char c);
void	ft_putnbr(long nbr);
void	ft_putstr(char *str);
void	ft_dectohex(void *str, int i);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_atoi(const char *s1);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);
