#ifndef FT_PRINTF_H
#define FT_PRINTF_H

typedef struct	s_list
{
	char			print_char;
	char			*print_string;
	void			*pointer;
	int				print_signed;
	unsigned int	print_unsigned;
	int				hexnum;
	int				zero;
	int				dash;
	int				asterisk;
	int				point;
	int				flag;
}				t_list;

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_case_c(va_list valist, int *character_count, t_list list);
void	ft_case_s(va_list valist, int *character_count, t_list list);
void	ft_case_p(va_list valist, int *character_count, t_list list);
void	ft_case_id(va_list valist, int *character_count, t_list list);
void	ft_case_u(va_list valist, int *character_count, t_list list);
void	ft_case_x(va_list valist, int *character_count, t_list list);
void	ft_case_mx(va_list valist, int *character_count, t_list list);
void	ft_case_percentage(va_list valist,  int *character_count, t_list list);
void	ft_last_case(va_list valist,  int *character_count);
void	ft_put_string(char *string);
void	ft_putchar(char c);
int		ft_strlen(char *string);
int		ft_count_nb(int nb);
void	ft_putnbr_fd(int nb);
char 	*ft_itoa_hex(long int num, int w);

#endif