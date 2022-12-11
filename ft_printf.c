/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:19:31 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 12:14:01 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;
	int		i;

	length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				length += ft_putnbr(va_arg(args, int));
			else if (str[i + 1] == 's')
				length += ft_putstr(va_arg(args, char *));
			else if (str[i + 1] == 'c')
				length += ft_putchar(va_arg(args, int));
			else if (str[i + 1] == 'x')
				length += ft_puthexlow(va_arg(args, unsigned int));
			else if (str[i + 1] == 'X')
				length += ft_puthexupp(va_arg(args, unsigned int));
			else if (str[i + 1] == 'u')
				length += ft_putunbr(va_arg(args, unsigned int));
			else if (str[i + 1] == 'p')
				length += ft_putstr("0x") + ft_putptr(va_arg(args, unsigned long));
			else if (str[i + 1] == '%')
				length += ft_putchar('%');
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	return (va_end(args), length);
}
