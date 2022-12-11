/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:08:49 by tmoumni           #+#    #+#             */
/*   Updated: 2022/12/11 12:56:56 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned int num, char c);
int	ft_puthexupp(unsigned int num);
int	ft_putnbr(int num);
int	ft_putptr(unsigned long num);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int num);

#endif