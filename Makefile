# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 09:29:36 by tmoumni           #+#    #+#              #
#    Updated: 2022/12/24 15:55:17 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

SRCS =  ft_printf.c utils/ft_putnbr.c utils/ft_putchar.c\
		utils/ft_putstr.c utils/ft_puthex.c\
		utils/ft_putunbr.c utils/ft_putptr.c

OBJS = $(SRCS:%.c=%.o)

GREEN=\033[1;32m
RED=\033[1;31m
CYAN=\033[1;36m
BOLD=\033[1m
END=\033[0m

all: $(NAME)
	@echo "\n$(GREEN)[ libftprintf.a ]$(END) created successfully!\n"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END) [$(BOLD) $< $(END)]"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\n$(CYAN)All files compiled and linked to the lib successfully...$(END)"

clean:
	@rm -f $(OBJS)
	@echo "\n$(RED)[ Files deleted successfully! ]$(END)\n"

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "\n$(RED)[ Files deleted successfully! ]$(END)\n"

re: fclean all

.PHONY: all clean fclean re