#include "ft_printf.h"

char	*ft_conversion(t_struct *out, va_list ap)
{
	char	*convchar;

	if (out->conversion == 'c')
	{
		convchar = malloc(sizeof(char) * 2);
		convchar[0] = va_arg(ap, int);
		convchar[1] = '\0';
	}
	else if (out->conversion  == 'd')
		convchar = ft_strdup(ft_itoa_base(va_arg(ap, int), 10));
	else if (out->conversion  == 's')
		convchar = ft_strdup(va_arg(ap, char *));
	else if (out->conversion  == 'u')
		convchar = ft_strdup(ft_itoa_base((unsigned int)va_arg(ap, unsigned int), 10));
	else if (out->conversion  == 'i')
		convchar = ft_strdup(ft_itoa_base((signed int)va_arg(ap, signed int), 10));
	else if (out->conversion  == 'p')
		convchar = ft_strjoin("0x",ft_itoa_base(va_arg(ap, unsigned long), 16));
	else if (out->conversion  == 'x')
		convchar = ft_itoa_base(va_arg(ap, unsigned int), 16);
	else if (out->conversion  == 'X')
		convchar = ft_itoa_base(va_arg(ap, unsigned int), 16);
	return (convchar);
}


t_struct    *ft_create_str(t_struct *out, va_list ap)
{
	int	realsz;
	int t2;
	char *convchar;

	convchar = ft_conversion(out, ap);
	realsz = ft_strlen(convchar);
	out->str = convchar;
	return(out);
}
