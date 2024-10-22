#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_base10(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += ft_putchar('-');
		count += ft_base10(-nb);
	}
	else if (nb > 9)
	{
		count += ft_base10(nb / 10);
		count += ft_base10(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_ptr(void *arg)
{
	int				count;
	char			*alpha;
	unsigned long	arg2;

	arg2 = (unsigned long)arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_putstr("0x");
	count += ft_base16(arg2, alpha);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_decimal10(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_base10(nb / 10);
		count += ft_base10(nb % 10);
	}
	else if (nb > 0 && nb < 10)
		count += ft_putchar(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_hexa(unsigned int nb, int type)
{
	char	*alpha;

	if (type == 'x')
		alpha = "0123456789abcdef";
	else
		alpha = "0123456789ABCDEF";
	return (ft_base16(nb, alpha));
}

int	ft_base16(unsigned long nb, char *alpha)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_base16(nb / 16, alpha);
		count += ft_base16(nb % 16, alpha);
	}
	else
		count += ft_putchar(alpha[nb]);
	if (count < 0)
		return (-1);
	return (count);
}
