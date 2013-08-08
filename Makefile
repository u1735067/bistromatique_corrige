
NAME		=		calc

NAME_LIB	=		libft.a

CC			=		gcc

RM			=		rm -f

CFLAGS		=		-Wextra -Werror -Wall -Iinclude

SRCS		=		srcs/main.c				\
					srcs/evalexpr.c			\
					srcs/creat_tree.c		\
					srcs/calc_tree.c		\
					srcs/op_infiny.c		\
					srcs/ft_add.c			\
					srcs/ft_sub.c			\
					srcs/ft_mul.c			

SRCS_LIB	=		lib/ft_putchar.c		\
					lib/ft_strlen.c			\
					lib/ft_putstr.c			\
					lib/ft_putnbr.c			\
					lib/ft_putnbr_base.c	\
					lib/ft_getnbr.c			\
					lib/ft_getnbr_base.c	\
					lib/ft_find_str.c		\
					lib/ft_concat_str.c		\
					lib/ft_strdup.c			\
					lib/ft_strcmp.c			\
					lib/ft_epur.c

OBJS		=		$(SRCS:.c=.o)

OBJS_LIB	=		$(SRCS_LIB:.c=.o)

all			:		$(NAME_LIB) $(NAME)

$(NAME_LIB)	:		$(OBJS_LIB)
					ar rc $(NAME_LIB) $(OBJS_LIB)
					ranlib $(NAME_LIB)

$(NAME)		:		$(OBJS)
					$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -L. -lft

clean		:
					$(RM) $(OBJS) $(OBJS_LIB)

fclean		:		clean
					$(RM) $(NAME) $(NAME_LIB)

re			:		fclean all

.PHONY		:		all clen fclean re
