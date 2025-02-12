CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = $(shell find -name "*.c") 

OBJ = $(SRC:.c=.o)

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
        ft_lstiter_bonus.c ft_lstlast_bonus.c \
        ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library created: $(NAME)"

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned library file $(NAME)"

re: fclean all

bonus: $(OBJ) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)
	@echo "Library with bonus files created: $(NAME)"

.PHONY: all clean fclean re bonus

