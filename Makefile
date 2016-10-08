##
## Makefile for  in /home/belfio_u/rendu/EXOTEST/FDF
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon Oct 27 15:13:44 2014 ugo belfiore
## Last update Mon Nov  3 01:48:08 2014 ugo belfiore
##

SRC     =       main.c		\
		evenement.c	\
		aff_line.c	\
		aff_line_2.c	\
		aff_line_3.c	\
		aff_line_4.c	\
		aff_pix_img.c	\
		aff_circle.c	\
		tab_test.c

OBJ     =       $(SRC:.c=.o)

NAME    =       tictac

LIB     =       lib/my/libmy.a

LIBMINI =	minilibx/libmlx.a

CC      =       gcc

CFLAGS  +=      -W -Wall -Wextra -ggdb3 -g3 -gstabs

LIB2	=	-L/usr/lib64/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBMINI) $(LIB2)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all

