# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:42:55 by rcoetzer          #+#    #+#              #
#    Updated: 2019/07/04 21:09:48 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =fdf
cc = gcc
CFLAGS = -Wall -Werror -Wextra

UNAME_S := $(shell uname -s)
LIBS = -L libft/ -lft

ifeq ($(UNAME_S),Linux)
	LIBS += -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	LIBS += -lmlx -framework OpenGL -framework AppKit
endif
INC = -I ./inc/ -I ./libft/inc/

SRC_DIR = src
OBJ_DIR = obj

INCF = libft/inc/libft.h inc/fdf.h inc/keydef.h
SRCF = mouse.c img.c draw.c rot.c apply.c hooks.c main.c handelfile.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRCF))
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCF:.c=.o))

$(NAME) : dirmake $(OBJS)
	@echo "\033[1;36;m\t\t\t[ DONE ]\t\t\033[0m"
	@$(cc) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCF)
	@echo "\033[1;95;m\t\tCompiling \t\033[1;96;m$<]\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

dirmake:
	@mkdir -p obj
	@echo "\033[1;36;m\t\t\t COMPILING LIBFT\n \033[0m"
	@make -C libft

all: dirmake $(NAME)


clean:
	@echo "\033[1;31;m\t\t\t[ Cleaning ]\033[0m"
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all
	@echo "\033[1;92m\t\t\t[ Recompiled $(NAME)! ]\033[0m"

.PHONY: clean fclean all re
