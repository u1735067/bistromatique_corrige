
#include	<stdlib.h>
#include	"bistromatique.h"
#include	"ft.h"

int			*ft_malloc_tmp(unsigned int size)
{
	int		*res;
	unsigned int		i;

	i = 0;
	if ((res = (int *)malloc(sizeof(*res) * (size))) ==  NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

int			ft_digit(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}


char		*ft_add_neg(char *nb, char *ops)
{
	char	*res;
	int		i;

	i = 0;
	if ((res = malloc(sizeof(*res) * (ft_strlen(nb) + 2))) == NULL)
	{
		return (NULL);
	}
	res[0] = ops[3];
	while (nb[i] != '\0')
	{
		res[i + 1] = nb[i];
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

int			ft_nbrcmp(char *s1, char *s2, char *base)
{
	int		i;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
	{
		return (1);
	}
	else if (ft_strlen(s1) < ft_strlen(s2))
    {
		return (-1);
    }
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (ft_digit(s1[i], base) - ft_digit(s2[i], base));
}

char        *ft_inf(char *n1, char *n2, char *base, int *(func)())
{
    int     *tmp;
    char    *res;
    int     i;
    int     size;

    i = 0;
    size = ft_strlen(n1) + ft_strlen(n2);
    if ((tmp = ft_malloc_tmp(size)) == NULL)
    {
        return (NULL);
    }
    tmp = func(n1, n2, base, tmp);
    if ((res = (char *)malloc(sizeof(*res) * (size + 1))) == NULL)
    {
        return (NULL);
    }
    res[size] = '\0';
    while (i < size)
    {
        res[i] = base[tmp[i]];
		i++;
	}
    free(tmp);
//	printf("RRESSS == %s\n", res);
    return (ft_epur(res, base[0]));
}
