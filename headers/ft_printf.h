/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:57:16 by acharlas          #+#    #+#             */
/*   Updated: 2019/11/15 18:15:41 by acharlas         ###   ########.fr       */
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

t_struct	*ft_init_struct(t_struct *out);
t_struct	*ft_fill_struct(t_struct *out,const char *str, va_list ap);
t_struct	*ft_create_str(t_struct *out, va_list ap);
char		*ft_strndup(char *s, int n);
char		*argptr(t_struct *out,char *convptr);
char		*ft_substr(char *s, int start, int len);
char		*argstr(t_struct *out,char *convstr);
char		*argnum(t_struct *out, char *convchar);
char		*ft_strdup(char *s);
char		*ft_tolower(char *str);
char		*ft_itoa_base(long long c, int n_base);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isdigit(int c);
int			ft_atoi(const char *s1);
int			ft_strlen(char *str);
int			ft_printf(const char *str, ...);
