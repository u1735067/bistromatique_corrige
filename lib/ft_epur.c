
#include	"ft.h"

char		*ft_epur(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i + 1] != '\0' && str[i] == c)
	{
		i++;
	}
	return (&str[i]);
}
