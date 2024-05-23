# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgori <fgori@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 13:25:31 by fgori             #+#    #+#              #
#    Updated: 2024/05/23 10:35:04 by fgori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = src/collectible_var.c\
			src/convert_img.c\
			src/so_long.c\
			src/move.c\
			src/print_image.c\
			src/mostr_move.c\
			src/mapplayer.c\
			src/map.c\
			src/utilis.c
CFLAG = -Wall -Wextra -Werror -g
CC = cc

LFT = ./libft
LIBFT = $(LFT)/libft.a

DIR_MLX = ./minilibx
MLX = $(DIR_MLX)/libmlx.a
MFLAG = -lX11 -lm -lXext

NAME = so_long.out

all:$(NAME)

$(NAME):
		if [ -e ./minilibx-linux ] && [ ! -e $(DIR_MLX) ]; then \
    		mv minilibx-linux $(DIR_MLX); \
		fi
		@make all -C $(LFT)
		@make bonus -C $(LFT)
		@make all -C $(DIR_MLX)
		@$(CC) -fPIE $(CFLAG) -I./ -I$(LFT)/lib -L$(LFT) $(FILE) $(MLX) $(MFLAG) $(LIBFT) -pthread -o $(NAME)
		@echo "all ok"

clean:
		make clean -C $(LFT)

fclean: clean
		make fclean -C $(LFT)
		make clean -C $(DIR_MLX)
		@rm -f $(NAME)

re: fclean all 

replay: 
		@rm -f $(NAME)
		@$(CC) $(CFLAG) $(FILE) $(LIBFT) $(MLX) $(MFLAG) -o $(NAME)
		@echo "all ok"

.PHONY: all clean fclean re replay