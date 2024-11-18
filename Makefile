# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 01:42:16 by scruz-ra          #+#    #+#              #
#    Updated: 2024/09/25 01:42:16 by scruz-ra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -L/usr/lib -lXext -lX11

INCLUDES	= ./includes/so_long.h
LIBFT 		= ./libft/libft.a
SRCDIR 		= ./src/
OBJFILES	= ./obj/

CYAN		= \033[38;5;45m
PINK		= \033[38;5;207m
RED			= \033[31m
YELLOW		= \033[38;5;220m
GREEN		= \033[32m
RESET		= \033[0m

SRC			= $(SRCDIR)so_long.c $(SRCDIR)read_map.c $(SRCDIR)map_check.c $(SRCDIR)print_map.c \
				$(SRCDIR)error_utils.c $(SRCDIR)init.c $(SRCDIR)read_utils.c $(SRCDIR)checks.c \

OBJ			= $(SRC:$(SRCDIR)%.c=$(OBJFILES)%.o)

all: $(NAME)
	@echo ""
	@echo "$(CYAN).$(PINK)▄▄ $(CYAN)·           $(CYAN)▄▄▌         ▐ ▄  ▄▄ $(PINK)• $(RESET)"
	@echo "$(PINK)▐█ ▀$(CYAN). ▪         $(CYAN)██$(PINK)•  ▪     •$(CYAN)█▌▐█▐█ ▀ $(PINK)▪$(RESET)"
	@echo "$(PINK)▄▀▀▀█▄ ▄█▀▄     $(CYAN)██$(PINK)▪   $(CYAN)▄█▀▄ ▐█▐▐▌▄█ ▀█▄$(RESET)"
	@echo "$(PINK)▐█▄$(CYAN)▪$(PINK)▐█▐█▌$(CYAN).$(PINK)▐▌    $(CYAN)▐█▌▐▌▐█▌$(PINK).$(CYAN)▐▌██▐█▌▐█▄$(PINK)▪$(CYAN)▐█$(RESET)"
	@echo "$(PINK) ▀▀▀▀  ▀█▄▀$(CYAN)▪    $(PINK).$(CYAN)▀▀▀  ▀█▄▀$(PINK)▪$(CYAN)▀▀ █$(PINK)▪·$(CYAN)▀▀▀▀ $(RESET)"
	@echo "" 
	@echo "$(YELLOW)COMPILATION: $(GREEN)| OK!$(RESET)"
	@echo "$(YELLOW)FILE:        $(GREEN)| $(NAME)$(RESET)"
	
$(NAME): $(OBJ)
	@cd libft && $(MAKE) 2>&1 | grep -E "Compiling|error|fatal" || true
	@make -C mlx > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJFILES)%.o: $(SRCDIR)%.c $(INCLUDES)
	@mkdir -p $(OBJFILES)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@cd libft && make clean 2>&1 | grep -E "Compiling|error|fatal" || true
	@cd mlx && make clean 2>&1 | grep -E "Compiling|error|fatal" || true
	@rm -rf $(OBJFILES)
	@echo "$(RED)OBJECTS:     | CLEANED!$(RESET)"

fclean: clean
	@cd libft && make fclean 2>&1 | grep -E "Compiling|error|fatal" || true
	@cd mlx && make clean 2>&1 | grep -E "Compiling|error|fatal" || true
	@rm -rf $(NAME)
	@echo "$(RED)All:	     | CLEANED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
 