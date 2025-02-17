# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 09:31:27 by ggargani          #+#    #+#              #
#    Updated: 2025/02/13 14:45:33 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I./libraries/MLX42/include


SRCS = src/main.c src/utils.c src/map_validation.c src/map_validation_2.c \
	src/player.c src/read_file.c src/rendering.c src/rendering_2.c


OBJS = $(SRCS:.c=.o)


NAME = so_long


MLX42_DIR = ./libraries/MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_LIB = $(MLX42_BUILD)/libmlx42.a

LIBFT_PATH = ./libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a


LIBS = $(MLX42_LIB) -ldl -lglfw -pthread -lm $(LIBFT)


all: $(NAME)

$(NAME): $(MLX42_LIB) $(LIBFT) $(OBJS)
	@echo "------------ Compiling $(NAME) ------------"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) $(CFLAGS)
	@echo "$(NAME) compiled successfully!"

$(MLX42_LIB):
	@echo "------------ Compiling MLX42 ------------"
	@if [ ! -d $(MLX42_DIR) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	fi
	@if [ ! -d $(MLX42_BUILD) ]; then \
		cmake -S $(MLX42_DIR) -B $(MLX42_BUILD) && \
		cmake --build $(MLX42_BUILD) --parallel; \
	fi

$(LIBFT):
	@echo "------------ Compiling libft ------------"
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "------------ Object files cleaned ------------"

fclean: clean
	
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "------------ Executable removed ------------."

re: fclean all

.PHONY: all clean fclean re



