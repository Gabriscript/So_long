# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 09:31:27 by ggargani          #+#    #+#              #
#    Updated: 2025/02/13 11:22:33 by ggargani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I includes -I libft

SRCS = src/main.c src/utils.c src/map_validation.c src/map_validation_2.c \
	src/player.c src/read_file.c src/rendering.c

LIBMLX = ./libraries/MLX42
MLX = $(LIBMLX)/build/libmlx42.a
LIBS = $(MLX) -ldl -lglfw -pthread -lm

LIBFT_PATH = ./libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		@echo "Compiled executables"
		$(CC) $(OBJS) $(LIBS) $(HEADERS)  $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT):
		@echo "--------------- Compiled Libft ---------------"
		@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
		@echo "--------------- Compiled MLX42 ---------------"
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f .bonus

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -rf $(LIBMLX)/build


re: fclean all

.PHONY: all clean fclean re libmlx