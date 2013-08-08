
#include		<stdlib.h>
#include		"bistromatique.h"
#include		"ft.h"

int			operate_priority(char c, int prio, char open_par, char close_par)
{
	if (c == open_par)
	{
		prio = prio + 2;
	}
	else if (c == close_par)
	{
		prio = prio - 2;
	}
	return (prio);
}

int			priority(char *str, int i, char *ops)
{
	int		prio;
	int		i_min;
	int		prio_min;

	prio = 0;
	i_min = -1;
	prio_min = -1;
	while (str[i] != '\0')
	{
		prio = operate_priority(str[i], prio, ops[0], ops[1]);
		if ((str[i] == ops[2] || str[i] == ops[3]) &&
				 (i_min == -1 || prio_min >= prio))
		{
			prio_min = prio;
			i_min = i;
		}
		else if ((str[i] == ops[4] || str[i] == ops[5] || str[i] == ops[6]) &&
				 (i_min == -1 || prio_min >= prio + 1))
		{
			prio_min = prio + 1;
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

char			*ft_epur_str(char *str, char *base, char *ops)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	while (str[i] != '\0' &&
		   ft_find_str(ft_concat_str(base, &ops[2]), str[i]) < 0)
	{
		i++;
	}
	a = i;
	while (ft_find_str(base, str[i]) >= 0)
	{
		i++;
	}
	str[i] = '\0';
	if (str[a] == '\0')
	{
		return (ft_strdup("0"));
	}
	return (ft_strdup(&str[a]));
}

t_tree			*creat_tree(char *str, char *base, char *ops)
{
    t_tree		*element;
    int			i;

//	printf("str == %s\n", str);
	if ((element = (t_tree *)malloc(sizeof(*element))) == NULL)
	{
		return (NULL);
	}
	if ((i = priority(str, 0, ops)) >= 0)
	{
		element->op = ft_find_str(ops, str[i]);
		element->nb = NULL;
		str[i++] = '\0';
		element->left = creat_tree(str, base, ops);
		element->right = creat_tree(&str[i], base, ops);
	}
	else
	{
		element->op = -1;
//		printf("----------> %s\n", ft_epur_str(str, base, ops));
		element->nb = ft_epur_str(str, base, ops);
		element->left = NULL;
		element->right = NULL;
	}
//	printf("op == %d, nb = %s\n", element->op, element->nb);
	return (element);
}
