SRC_PATH = 		srcs/
SRC_NAME =		cercle.c \
				main.c \
				
SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH =		objs/
OBJ_NAME = 		$(SRC_NAME:.c=.o)
OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))



INC = 			-I include -I libft

LDLIBS = 		-lft
LDFLAGS = 		-Llibft
LIBFT_PATH = 	libft/
LIBFT = 		$(LIBFT_PATH)libft.a

CC = 			clang
CFLAGS = 		-Wall -Wextra -Werror
NAME = 			"fract'ol"

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(INC) $(LDFLAGS) $(LDLIBS) -L mlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p objs
	$(CC) $(CFLAGS) $(INC) $(CPPFLAGS) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	rm -rfv $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -fv $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all
