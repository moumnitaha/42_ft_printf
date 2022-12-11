/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:50:43 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 10:33:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	int	length;

	length = 0;
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
		length += ft_putunbr(num / 10);
		length += ft_putunbr((num % 10));
	}
	return (length);
}
