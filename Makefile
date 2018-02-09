##
## Makefile for fdf in /home/plasko_a/rendu/MUL_2013_fdf
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Thu Nov 21 08:52:14 2013 Antoine Plaskowski
## Last update Sun Dec  8 16:34:29 2013 Antoine Plaskowski
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-I include/ -I libft

LDFLAGS	+=	-L minilibx -l mlx -L libft
LDFLAGS	+=	-L/usr/lib64/X11 -l Xext -l X11 -lft

NAME	=	fract-ol

SRC	+=	src/fract-ol.c
SRC	+=	src/print_color.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(MAKE) -C minilibx
		$(MAKE) -C libft
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
