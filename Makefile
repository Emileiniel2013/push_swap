# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: temil-da <temil-da@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 19:58:35 by temil-da          #+#    #+#              #
#    Updated: 2024/05/14 22:17:02 by temil-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT_DIR = Utils/libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC =  helper_functions.c main.c operations.c operations_2.c operations_3.c \
	push_swap.c the_brain.c the_brain_2.c helper_functions_2.c 

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

RED = \033[0;31m
NC = \033[0m
GREEN = \033[0;32m
YELLOW = \033[1;33m

.PHONY: all clean fclean re compile_msg


all : compile_msg $(NAME) $(LIBFT)

compile_msg:
	@echo "$(YELLOW)Compiling source files...$(NC)\n$(GREEN)Done.$(NC)"

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)Creating $(NAME) executable$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)Done.$(NC)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling libft.a source files...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 && echo "$(GREEN)Done.$(NC)" || (echo "$(RED)Error compiling libft.a$(NC)" && exit 1)

clean:
	@$(if $(wildcard $(OBJ)), \
        echo "$(YELLOW)Cleaning object files...$(NC)" && rm -f $(OBJ) && echo "$(GREEN)Done.$(NC)", \
        echo "$(RED)No object files to clean!$(NC)")
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean 
	@$(if $(wildcard $(NAME)), \
        echo "$(YELLOW)Removing $(NAME) executable...$(NC)" && rm -f $(NAME) && echo "$(GREEN)Done.$(NC)", \
        echo "$(RED)$(NAME) executable non existent!$(NC)")
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
