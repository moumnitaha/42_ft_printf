# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 09:29:36 by tmoumni           #+#    #+#              #
#    Updated: 2022/12/11 11:46:10 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRCS = ft_printf.c utils/ft_putnbr.c utils/ft_putchar.c\
	utils/ft_putstr.c utils/ft_puthexlow.c\
	utils/ft_puthexupp.c utils/ft_putunbr.c utils/ft_putptr.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)
	@echo "libftprintf.a created successfully!"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "Compiling:" $< "..."

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Compiled successfully...."

clean:
	@rm -f $(OBJS) $(B_OBJS)

fclean:
	@rm -f $(NAME) $(OBJS) $(B_OBJS)

re: fclean all

.PHONY: all clean fclean re