#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int main(void)
{
	ft_printf("%-5.0u\n",0);
	printf("%-5.0u\n",0);
	sleep(10);
	return (0);
}
