# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 15:53:10 by becamino          #+#    #+#              #
#    Updated: 2023/08/03 15:53:13 by becamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# alias.
LIB =   ar rcs
RM  =   rm -f
CC  =   gcc
CFLAGS  =   -Wall -Wextra -Werror  -I ./include -I ./libft/ ${DEBUG}
MLX = ./mlx/libmlx.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
DEBUG   =   -g3 -fsanitize=address
# DEBUG   =   
NAME    =   so_long

# sources and objects.
RR  =   so_long.c error_n_close.c checkmap.c lst_utils.c lst_utils2.c parsemap.c \
			checkpath.c checkpath2.c checkpath3.c init_map.c init_map2.c \
			move_right.c move_left.c move_elements.c move_up.c move_down.c \
			load_images.c
SRCR_DIR    =   ./src/
SRCR    =   $(addprefix $(SRCR_DIR), $(RR))
OBJ_DIR =   ./obj/
OBJ_FILES   =   $(RR:.c=.o)
OBJ =   $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

# compilation.
all: $(OBJ_DIR) $(NAME)

$(LIBFT):$(LIBFT_PATH)
	@make -sC $(LIBFT_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRCR_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "So_long compiled! :D\n"

clean:
	@$(RM) $(OBJ)
	@make clean -sC libft
	@rm -rf $(OBJ_DIR)
	@echo "All .o files removed :D\n"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC libft
	@rm -f $(OBJ_DIR)
	@echo "All removed D:\n"

re: fclean all

.PHONY: all clean fclean re