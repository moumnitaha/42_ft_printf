/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:49:27 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 11:33:30 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexupp(unsigned int num)
{
	int		length;
	char	*hex;

	length = 0;
	hex = "0123456789ABCDEF";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		length++;
	}
	else
	{
		length += ft_puthexupp(num / 16);
		length += ft_puthexupp(num % 16);
	}
	return (length);
}
