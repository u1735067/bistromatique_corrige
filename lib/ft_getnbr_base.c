
#include	<stdlib.h>
#include	"ft.h"

#include	<unistd.h>

int			ft_getnbr_base(char *str, char *base)
{
	int		res;
	int		a;
	int		i;

	res = 0;
	i = 0;
	if (str != NULL && str[0] == '-')
	{
		return (-ft_getnbr_base(&str[1], base));
	}
	while (str[i] != '\0')
	{
		a = 0;
		while (base[a] != str[i])
		{
			a++;
		}
		res = (res * ft_strlen(base)) + a;
		i++;
	}
	return (res);
}
