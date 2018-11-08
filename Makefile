.PHONY: all,clean,fclean,re

CC = /usr/bin/gcc

RM = /bin/rm

NAME = wolf3d

SRC = ./main.c\
	  ./ft_struct.c\
	  ./ft_parse.c\
	  ./get_size_lab.c\
	  ./ft_image.c\
	  ./ft_chartoint.c\
	  ./ft_deal_key.c\
	  ./ft_deal_mouse.c\


OBJ = ./main.o\
	  ./ft_struct.o\
	  ./get_size_lab.o\
	  ./ft_image.o\
	  ./ft_parse.o\
	  ./ft_chartoint.o\
	  ./ft_deal_key.o\
	  ./ft_deal_mouse.o\


LIBD = ./libft/

LIBFT = $(LIBD)libft.a

FLAGS = -Wall -Wextra -Werror

IMLX = /usr/local/include

LMLX = /usr/local/lib/

FFLAGS = -framework OpenGL -framework AppKit

HEADER = ./wolf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBD) Makefile
	@$(MAKE) -C $(LIBD)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I $(IMLX) -L $(LMLX) -lmlx $(FFLAGS)

clean:
	@$(RM) -f $(OBJ)
	@$(MAKE) -C $(LIBD) clean

fclean: clean
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(LIBD) fclean

re: fclean all