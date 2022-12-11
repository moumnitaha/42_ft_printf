/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:51:40 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 10:29:52 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(unsigned long num)
{
	int		length;
	char	*hex;

	length = 0;
	hex = "0123456789abcdef";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		length++;
	}
	else
	{
		length += ft_putptr(num / 16);
		length += ft_putptr(num % 16);
	}
	return (length);
}
