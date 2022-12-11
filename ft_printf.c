/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:19:31 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 12:45:45 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				length += ft_putnbr(va_arg(args, int));
			else if (*str == 's')
				length += ft_putstr(va_arg(args, char *));
			else if (*str == 'c')
				length += ft_putchar(va_arg(args, int));
			else if (*str == 'x')
				length += ft_puthexlow(va_arg(args, unsigned int));
			else if (*str == 'X')
				length += ft_puthexupp(va_arg(args, unsigned int));
			else if (*str == 'u')
				length += ft_putunbr(va_arg(args, unsigned int));
			else if (*str == 'p')
				length += ft_putstr("0x") + ft_putptr(va_arg(args, unsigned long));
			else if (*str == '%')
				length += ft_putchar('%');
		}
		else
			length += ft_putchar(*str);
		str++;
	}
	return (va_end(args), length);
}
