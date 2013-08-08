
#ifndef		FT_H
# define	FT_H

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_getnbr(char *str);
int			ft_getnbr_base(char *str, char *base);
void		ft_putnbr(int nb);
void		ft_putnbr_base(int nb, char *base);
int			ft_find_str(char *str, char c);
char		*ft_concat_str(char *s1, char *s2);
char		*ft_strdup(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_epur(char *str, char c);

#endif
