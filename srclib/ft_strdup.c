#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	if (!(dest = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
