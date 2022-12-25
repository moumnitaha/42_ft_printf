/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:50:43 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/25 18:14:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	int	length;

	length = 0;
	if (num < 10)
		length += ft_putchar(num + '0');
	else
	{
		length += ft_putunbr(num / 10);
		length += ft_putunbr((num % 10));
	}
	return (length);
}
