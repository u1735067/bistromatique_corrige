

#include	<stdlib.h>
#include	"bistromatique.h"
#include	"ft.h"

// FT_SUB_INF : PAS A LA NORME

int         *ft_sub_inf(char *n1, char *n2, char *base, int *res)
{
	int		p1;
	int		p2;
	int		i;
	int		base_len;

	p1 = ft_strlen(n1) - 1;
	p2 = ft_strlen(n2) - 1;
	i = p1 + p2;
	base_len = ft_strlen(base);
	while (p2 >= 0)
	{
		res[i + 1] += ft_digit(n1[p1--], base) - ft_digit(n2[p2--], base);
		if (res[i + 1] < 0)
		{
			res[i] -= 1;
			res[i + 1] = base_len + res[i + 1];
		}
		i--;
	}
	i++;
	while (p1 >= 0)
    {
		if (res[i + 1] < 0)
        {
            res[i] -= 1;
            res[i + 1] = base_len + res[i + 1];
        }
        res[i--] += ft_digit(n1[p1--], base);
    }
	return (res);
}

char        *ft_inter_sub(char *n1, char *n2, char *base, char *ops)
{
    if (ft_nbrcmp(n1, n2, base) >= 0)
    {
        return (ft_inf(n1, n2, base, &ft_sub_inf));
    }
    else
    {
        return (ft_add_neg(ft_inf(n2, n1, base, &ft_sub_inf), ops));
    }
}

char		*ft_sub(char *n1, char *n2, char *base, char *ops)
{
	if (ft_strcmp(n1, SYNTAXE_ERROR_MSG) == 0 ||
        ft_strcmp(n2, SYNTAXE_ERROR_MSG) == 0)
    {
        return (SYNTAXE_ERROR_MSG);
    }
	else if (n1[0] == ops[3] && n2[0] == ops[3])
	{
		return (ft_inter_sub(&n2[1], &n1[1], base, ops));
	}
	else if (n1[0] == ops[3])
	{
		return (ft_add_neg(ft_add(&n1[1], n2, base, ops), ops));
	}
	else if (n2[0] == ops[3])
	{
		return (ft_add(n1, &n2[1], base, ops));
	}
	else
	{
		return (ft_inter_sub(n1, n2, base, ops));
	}
}
