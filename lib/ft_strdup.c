
#include	<stdlib.h>
#include	"ft.h"

char		*ft_strdup(char *str)
{
	int		i;
	char	*new;

	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if ((new = malloc(sizeof(*new) * (i + 1))) == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
