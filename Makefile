# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 17:03:39 by junhhong          #+#    #+#              #
#    Updated: 2024/05/27 10:27:57 by junhhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIBFT = libft/libft.a -L minilibx-linux -lmlx_Linux -lX11 -lXext
NAME = so_long
AR = ar -rcs

SRC = so_long map map2 map_build ft_functions movement util1 valid_path

all : $(NAME)

SRCOBJ = $(addsuffix .o, $(SRC))

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(SRCOBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(SRCOBJ) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(SRCOBJ)
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf ${NAME}

re: fclean all

lib :
	$(MAKE) -C $(LIBDIR)/

libclean :
	$(MAKE) -C $(LIBDIR)/ clean

libfclean :
	$(MAKE) -C $(LIBDIR)/ fclean