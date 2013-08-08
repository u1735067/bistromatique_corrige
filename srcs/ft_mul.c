
#include	<stdlib.h>
#include	"bistromatique.h"
#include	"ft.h"

int			*ft_mul_inf(char *n1, char *n2, char *base, int *res)
{
	int		l1;
	int		l2;
	int		p1;
	int		p2;
	int		base_len;

	l1 = ft_strlen(n1);
	l2 = ft_strlen(n2);
	base_len = ft_strlen(base);
	p1 = l1 - 1;
	while (p1 >= 0)
	{
		p2 = l2 - 1;
			while (p2 >= 0)
			{
				res[p1 + p2 + 1] += ft_digit(n1[p1], base) * ft_digit(n2[p2], base);
				res[p1 + p2] += res[p1 + p2 + 1] / base_len;
				res[p1 + p2 + 1] = res[p1 + p2 + 1] % base_len;
				p2--;
			}
		p1--;
	}
	return (res);
}

char		*ft_mul(char *n1, char *n2, char *base, char *ops)
{
	if (ft_strcmp(n1, SYNTAXE_ERROR_MSG) == 0 ||
        ft_strcmp(n2, SYNTAXE_ERROR_MSG) == 0)
    {
        return (SYNTAXE_ERROR_MSG);
    }
	else if (n1[0] == ops[3] && n2[0] == ops[3])
	{
		return (ft_inf(&n1[1], &n2[1], base, &ft_mul_inf));
	}
	else if (n1[0] == ops[3])
	{
		return (ft_add_neg(ft_inf(&n1[1], n2, base, &ft_mul_inf), ops));
	}
	else if (n2[0] == ops[3])
	{
		return (ft_add_neg(ft_inf(n1, &n2[1], base, &ft_mul_inf), ops));
	}
	else
	{
		return (ft_inf(n1, n2, base, &ft_mul_inf));
	}
}
