/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:19:31 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/10 14:56:27 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	prthexlow(int num)
{
	static int	length;
	char		hex[16] = "0123456789abcdef";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		length++;
	}
	else
	{
		prthexlow(num / 16);
		prthexlow(num % 16);
	}
	return (length);
}

int	prthexupp(int num)
{
	static int	length;

	char hex[16] = "0123456789ABCDEF";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		length++;
	}
	else
	{
		prthexupp(num / 16);
		prthexupp(num % 16);
	}
	return (length);
}

int	prthexloww(unsigned long num)
{
	static int	length;

	char hex[16] = "0123456789abcdef";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		length++;
	}
	else
	{
		prthexloww(num / 16);
		prthexloww(num % 16);
	}
	return (length);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		ft_putchar(str[length]);
		length++;
	}
	return (length);
}

int	prtnum(int num)
{
	static int	length;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		length++;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		length++;
	}
	else
	{
		prtnum(num / 10);
		prtnum((num % 10));
	}
	return (length);
}

int	prtnumi(int num)
{
	static int	length;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		length++;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		length++;
	}
	else
	{
		prtnumi(num / 10);
		prtnumi((num % 10));
	}
	return (length);
}

int	prtunum(unsigned int num)
{
	static int	length;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		length++;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		length++;
	}
	else
	{
		prtunum(num / 10);
		prtunum((num % 10));
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int	length;

	length = 0;
	va_list args;
	va_start(args, str);
	int i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				length += prtnum(va_arg(args, int));
			else if (str[i] == 'i')
				length += prtnumi(va_arg(args, int));
			else if (str[i] == 's')
				length += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'c')
				length += ft_putchar(va_arg(args, int));
			else if (str[i] == 'x')
				length += prthexlow(va_arg(args, unsigned int));
			else if (str[i] == 'X')
				length += prthexupp(va_arg(args, unsigned int));
			else if (str[i] == 'u')
				length += prtunum(va_arg(args, unsigned int));
			else if (str[i] == 'p')
			{
				length += ft_putstr("0x");
				length += prthexloww(va_arg(args, unsigned long));
			}
			else if (str[i] == '%')
				length += ft_putchar('%');
		}
		else
		{
			length += ft_putchar(str[i]);
		}
		i++;
	}
	return (va_end(args), length);
}

int main()
{
	char *s = "Taha Moumni";
	printf("%d\n", printf("string is: %d %i %c %s %p %x %X %u %%\n", 125, 77, 'a', "Taha Moumni", s, 125, 123, -10));
	printf("%d\n", ft_printf("string is: %d %i %c %s %p %x %X %u %%\n", 125, 77, 'a', "Taha Moumni", s, 125, 123, -10));
}