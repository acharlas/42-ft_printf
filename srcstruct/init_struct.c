#include "ft_printf.h"

t_struct    *ft_init_struct(t_struct *out)
{
	out->str = NULL;
	out->precision = 0;
	out->width = 0;
	out->conversion = '\0';
	out->flag = 0;
	return (out);
}
