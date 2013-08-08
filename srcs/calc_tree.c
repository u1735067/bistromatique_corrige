
#include		"bistromatique.h"

t_op                tab_op[] =
{
    {OP_PLUS_IDX, &ft_add},
    {OP_SUB_IDX, &ft_sub},
    {OP_MULT_IDX, &ft_mul},
};

char			*calc_tree(t_tree *element, char *base, char *ops)
{
	int			i;

	i = 0;
//	printf("op == %d, nb == %s\n", element->op, element->nb);
	while (i < NB_OPS)
	{
		if (element->op == tab_op[i].operator)
		{
			return (tab_op[i].operation(calc_tree(element->left, base, ops),
										calc_tree(element->right, base, ops),
										base, ops));
		}
		i++;
	}
	return (element->nb);
}
