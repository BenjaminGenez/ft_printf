#include "ft_printf.h"

int	ft_type_check(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_putchar(va_arg(args, int));
	if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_base10(va_arg(args, int));
	if (type == 'p')
		count += ft_ptr(va_arg(args, void *));
	if (type == 'u')
		count += ft_decimal10(va_arg(args, unsigned int));
	if (type == 'X' || type == 'x')
		count += (char)ft_hexa(va_arg(args, int), type);
	if (type == '%')
		return (write(1, "%", 1));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_type_check(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	if (count < 0)
		return (-1);
	return (count);
}

int main()
{
	char *str = " world";
	ft_printf("Hello %s", str);

	ft_printf("Hello %x, ", str);
	ft_printf("Hello %s", str);
	ft_printf("Hello %s", str);
	ft_printf("Hello %s", str);
	ft_printf("Hello %s", str);
	ft_printf("Hello %s", str);
	return 0;
}
