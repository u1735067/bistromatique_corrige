
#include	<stdlib.h>
#include	"ft.h"

int			ft_getnbr(char *str)
{
	int		res;

	res = 0;
	if (str != NULL && str[0] == '-')
	{
		return (-ft_getnbr(&str[1]));
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res);
}
