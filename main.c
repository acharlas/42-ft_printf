#include "./headers/ft_printf.h"

int main()
{
	int i;
	int j;

	i = ft_printf("%");
	j = printf("%");
	printf("%d - %d\n", i, j);
	return (0);
}