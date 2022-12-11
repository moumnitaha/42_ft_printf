/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:47:58 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 11:32:48 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexlow(unsigned int num)
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
		length += ft_puthexlow(num / 16);
		length += ft_puthexlow(num % 16);
	}
	return (length);
}
