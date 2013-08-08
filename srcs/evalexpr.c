

#include	<unistd.h>
#include	<stdlib.h>
#include	"bistromatique.h"
#include	"ft.h"

int			eval_expr(char *base, char *ops, char *expr)
{
	t_tree	*ptr;

	ptr = creat_tree(expr, base, ops);
	if (ptr == NULL)
	{
        return (0);
    }
	ft_putstr(calc_tree(ptr, base, ops));
	ft_putchar('\n');
	return (1);
}
