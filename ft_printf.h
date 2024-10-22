#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_type_check(const char type, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_base10(int nb);
int	ft_decimal10(unsigned int nb);
int	ft_hexa(unsigned int nb, int type);
int	ft_ptr(void *arg);
int	ft_base16(unsigned long nb, char *alpha);

#endif
