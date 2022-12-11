/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:45:00 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 10:21:39 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	length;

	if (!str)
		str = "(null)";
	length = 0;
	while (str[length])
	{
		ft_putchar(str[length]);
		length++;
	}
	return (length);
}
