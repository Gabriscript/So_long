CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = $(shell find -name "*.c") 
#ft_atoi.c  ft_itoa.c   ft_putnbr_fd.c  ft_strlcpy.c  ft_tolower.c \
#      ft_bzero.c  ft_memchr.c ft_putstr_fd.c ft_strlen.c  ft_toupper.c \
#      ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
#      ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
#      ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
#      ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
#      ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
#      ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
#      ft_printf.c convert_c_manager.c ft_xxtoa.c convert_n_manager.c \
#      get_next_line.c get_next_line_utils.c

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

