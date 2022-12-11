/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:46:02 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 10:58:05 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int num)
{
	int	length;

	length = 0;
	if (num < 0)
	{
		if (num == INT_MIN)
			return (ft_putstr("-2147483648"));
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
		length += ft_putnbr(num / 10);
		length += ft_putnbr((num % 10));
	}
	return (length);
}
