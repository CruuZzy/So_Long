# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 17:23:48 by scruz-ra          #+#    #+#              #
#    Updated: 2024/11/06 08:54:02 by scruz-ra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= ./includes/libft.h
SRCDIR		= ./src/
OBJFILES	= ./obj/
PRINTF		= ./src/ft_printf/


CYAN		= \033[38;5;45m
PINK		= \033[38;5;207m
RED			= \033[31m
YELLOW		= \033[38;5;220m
GREEN		= \033[32m
RESET		= \033[0m

SRC 		= $(SRCDIR)ft_bzero.c $(SRCDIR)ft_memchr.c $(SRCDIR)ft_memcpy.c		\
			$(SRCDIR)ft_memmove.c $(SRCDIR)ft_memset.c $(SRCDIR)ft_atoi.c 		\
			$(SRCDIR)ft_isalnum.c $(SRCDIR)ft_isalpha.c $(SRCDIR)ft_isascii.c	\
			$(SRCDIR)ft_isdigit.c $(SRCDIR)ft_isprint.c $(SRCDIR)ft_memcmp.c	\
			$(SRCDIR)ft_tolower.c $(SRCDIR)ft_toupper.c $(SRCDIR)ft_strchr.c	\
			$(SRCDIR)ft_strnstr.c $(SRCDIR)ft_strrchr.c $(SRCDIR)ft_strlcat.c	\
			$(SRCDIR)ft_strlcpy.c $(SRCDIR)ft_strlen.c $(SRCDIR)ft_strncmp.c	\
			$(SRCDIR)ft_putchar_fd.c $(SRCDIR)ft_substr.c $(SRCDIR)ft_strjoin.c	\
			$(SRCDIR)ft_strtrim.c $(SRCDIR)ft_split.c $(SRCDIR)ft_strmapi.c		\
			$(SRCDIR)ft_striteri.c  $(SRCDIR)ft_strdup.c $(SRCDIR)ft_calloc.c	\
			$(SRCDIR)ft_putstr_fd.c $(SRCDIR)ft_putendl_fd.c $(SRCDIR)ft_itoa.c	\
			$(SRCDIR)ft_putnbr_fd.c $(SRCDIR)get_next_line.c					\
			$(SRCDIR)get_next_line_utils.c	$(SRCDIR)ft_strcmp.c				\

SRCPRINT	= $(PRINTF)ft_putchar.c $(PRINTF)ft_strlen.c						\
			$(PRINTF)ft_phexa.c  $(PRINTF)ft_print_hexa.c $(PRINTF)ft_putstr.c	\
			$(PRINTF)ft_printf.c $(PRINTF)ft_num_unsign.c $(PRINTF)ft_putnbr.c	\
			 
OBJ			= $(SRC:$(SRCDIR)%.c=$(OBJFILES)%.o) $(SRCPRINT:$(PRINTF)%.c=$(OBJFILES)ft_printf/%.o)

BONUSSRC 	= $(SRCDIR)ft_lstnew_bonus.c $(SRCDIR)ft_lstadd_front_bonus.c		\
			$(SRCDIR)ft_lstsize_bonus.c $(SRCDIR)ft_lstlast_bonus.c				\
			$(SRCDIR)ft_lstadd_back_bonus.c $(SRCDIR)ft_lstdelone_bonus.c		\
			$(SRCDIR)ft_lstclear_bonus.c $(SRCDIR)ft_lstiter_bonus.c			\
			$(SRCDIR)ft_lstmap_bonus.c											\

BONUSOBJ	= $(BONUSSRC:$(SRCDIR)%.c=$(OBJFILES)%.o)

OBJDIR		= $(OBJFILES) $(OBJFILES)ft_printf/

	
all: $(NAME)
	@echo "$(PINK)          _$(RESET)             $(CYAN) _           $(YELLOW)_                $(RED)_         $(GREEN)_       "
	@echo "$(PINK)        _\ \ $(RESET)          $(CYAN)/\ \        $(YELLOW)/ /\             $(RED)/\ \      $(GREEN)/\ \     "
	@echo "$(PINK)       /\__ \ $(RESET)         $(CYAN)\ \ \      $(YELLOW)/ /  \           $(RED)/  \ \     $(GREEN)\_\ \    "
	@echo "$(PINK)      / /_ \_\ $(RESET)        $(CYAN)/\ \_\    $(YELLOW)/ / /\ \         $(RED)/ /\ \ \    $(GREEN)/\__ \   "
	@echo "$(PINK)     / / /\/_/$(RESET)        $(CYAN)/ /\/_/   $(YELLOW)/ / /\ \ \       $(RED)/ / /\ \_\  $(GREEN)/ /_ \ \  "
	@echo "$(PINK)    / / /$(RESET)            $(CYAN)/ / /     $(YELLOW)/ / /\ \_\ \     $(RED)/ /_/_ \/_/ $(GREEN)/ / /\ \ \ "
	@echo "$(PINK)   / / /$(RESET)            $(CYAN)/ / /     $(YELLOW)/ / /\ \ \___\   $(RED)/ /____/\   $(GREEN)/ / /  \/_/ "
	@echo "$(PINK)  / / / ____ $(RESET)      $(CYAN)/ / /     $(YELLOW)/ / /  \ \ \__/  $(RED)/ /\____\/  $(GREEN)/ / /        "
	@echo "$(PINK) / /_/_/ ___/\ $(RESET)$(CYAN)___/ / /__   $(YELLOW)/ / /____\_\ \   $(RED)/ / /       $(GREEN)/ / /         "
	@echo "$(PINK)/_______/\__\/$(RESET)$(CYAN)/\__\/_/___\ $(YELLOW)/ / /__________\ $(RED)/ / /       $(GREEN)/_/ /          "
	@echo "$(PINK)\_______\/$(RESET)    $(CYAN)\/_________/ $(YELLOW)\/_____________/ $(RED)\/_/        $(GREEN)\_\/           $(RESET)"
	@echo "" 
	@echo "$(YELLOW)COMPILATION: $(GREEN)| OK!$(RESET)"
	@echo "$(YELLOW)FILE:        $(GREEN)| $(NAME)$(RESET)"   

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJFILES)%.o: $(SRCDIR)%.c $(INCLUDES) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJFILES)ft_printf/%.o: $(PRINTF)%.c $(INCLUDES) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(BONUSOBJ)
	@ar rcs $(NAME) $(BONUSOBJ) -o $(NAME)
	@echo "$(YELLOW)BONUS:       | OK!$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)OBJECTS:     | CLEANED!$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)All:	     | CLEANED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re