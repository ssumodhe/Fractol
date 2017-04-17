# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 20:36:48 by ssumodhe          #+#    #+#              #
#    Updated: 2017/04/15 23:02:21 by ssumodhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
FLAGSMLX = -lmlx -framework OpenGL -framework Appkit
EXEC = fractol
LIBFT = libft/libft.a
SRCS = main_fract.c \
	   pick_fract.c \
	   julia_fract.c \
	   kitty_fract.c \
	   mandelbrot_fract.c \
	   display_fract.c \
	   display_2_fract.c

OBJS = $(SRCS:.c=.o)


all : $(EXEC)

$(EXEC) : $(OBJS) $(LIBFT)
	@clang $(FLAGS) $(FLAGSMLX) -o $@ $(LIBFT) $(SRCS)
	@echo "Fractol: \033[1;32mDONE\033[0m"

$(LIBFT) :
	@make -C libft

%.o: %.c
	@clang $(FLAGS) -o $@ -c $<

clean :
	@make -C libft clean
	@rm -rf *.o
	@echo "Fractol: clean: \033[1;32mDONE\033[0m"

fclean : clean
	@make -C libft fclean
	@rm -rf $(EXEC)
	@echo "Fractol: fclean: \033[1;32mDONE\033[0m"

re : fclean all
