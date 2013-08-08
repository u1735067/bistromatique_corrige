

#include	<stdlib.h>
#include	"bistromatique.h"
#include	"ft.h"

int			*ft_add_inf(char *n1, char *n2, char *base, int *res)
{
    int     p1;
    int     p2;
    int     base_len;
	int		ret;
	int		i;

    base_len = ft_strlen(base);
	p1 = ft_strlen(n1) - 1;
	p2 = ft_strlen(n2) - 1;
	i = p1 + p2;
	ret = 0;
	while (p2 >= 0)
	{
		res[i + 1] += (ft_digit(n1[p1--], base) + ft_digit(n2[p2--], base));
		res[i] += res[i + 1] / base_len;
		res[i + 1] = res[i + 1] % base_len;
		i--;
	}
	i++;
	while (p1 >= 0)
	{
		res[i--] += ft_digit(n1[p1--], base);
	}
	return (res);
}

char        *ft_inter_add(char *n1, char *n2, char *base)
{
    if (ft_nbrcmp(n1, n2, base) >= 0)
    {
        return (ft_inf(n1, n2, base, &ft_add_inf));
    }
    else
    {
        return (ft_inf(n2, n1, base, &ft_add_inf));
    }
}

char		*ft_add(char *n1, char *n2, char *base, char *ops)
{
//	printf("ADD : n1 == %s   n2 == %s\n", n1, n2);
	if (ft_strcmp(n1, SYNTAXE_ERROR_MSG) == 0 ||
		ft_strcmp(n2, SYNTAXE_ERROR_MSG) == 0)
	{
		return (SYNTAXE_ERROR_MSG);
	}
	else if (n1[0] == ops[3] && n2[0] == ops[3])
	{
		return (ft_inter_add(&n1[1], &n2[1], base));
	}
	else if (n1[0] == ops[3])
	{
		return (ft_sub(n2, &n1[1], base, ops));
	}
	else if (n2[0] == ops[3])
	{
		return (ft_sub(n1, &n2[1], base, ops));
	}
	else
	{
		return (ft_inter_add(n1, n2, base));
	}
}
