
#ifndef		BISTROMATIQUE_H
# define	BISTROMATIQUE_H

#include <unistd.h>
#include <stdio.h>

typedef	struct		s_tree
{
	int				op;
	char			*nb;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_op
{
	int				operator;
	char*(*operation)(char *, char *, char *, char *);
}					t_op;

#define		NB_OPS				5

#define		OP_OPEN_PARENT_IDX	0
#define		OP_CLOSE_PARENT_IDX	1
#define		OP_PLUS_IDX			2
#define		OP_SUB_IDX			3
#define		OP_MULT_IDX			4

#define		SYNTAXE_ERROR_MSG "syntax error\n"

// main.c

int			main(int ac, char **av);

// eval_expr.c

int			eval_expr(char *base, char *ops, char *expr);

// creat_tree.c

int			operate_priority(char c, int prio, char open_par, char close_par);
int			priority(char *str, int i, char *ops);
char		*ft_epur_str(char *str, char *base, char *ops);
t_tree		*creat_tree(char *str, char *base, char *ops);

// calc_tree.c

char		*calc_tree(t_tree *element, char *base, char *ops);

// op_infiny.c

char        *ft_inf(char *n1, char *n2, char *base, int *(func)());
int         ft_nbrcmp(char *s1, char *s2, char *base);
char        *ft_add_neg(char *nb, char *ops);
int         ft_digit(char c, char *base);
int         *ft_malloc_tmp(unsigned int size);

// ft_add.c

int         *ft_add_inf(char *n1, char *n2, char *base, int *res);
char        *ft_add(char *n1, char *n2, char *base, char *ops);

// ft_sub.c

int         *ft_sub_inf(char *n1, char *n2, char *base, int *res);
char        *ft_sub(char *n1, char *n2, char *base, char *ops);

// ft_mul.c

int         *ft_mul_inf(char *n1, char *n2, char *base, int *res);
char        *ft_mul(char *n1, char *n2, char *base, char *ops);

#endif
