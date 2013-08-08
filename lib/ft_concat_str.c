
#include	<stdlib.h>
#include	"ft.h"

char		*ft_concat_str(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		a;

	i = 0;
	a = 0;
	res = (char *)malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		res[i] = s2[a];
		i++;
		a++;
	}
	res[i] = '\0';
	return (res);
}
