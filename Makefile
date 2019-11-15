# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:51:14 by rcoetzer          #+#    #+#              #
#    Updated: 2019/07/12 12:23:21 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
cc = gcc
CFLAGS =-Wall -Werror -Wextra

LIBS= -L libft/ -lft

UNAME_S := $(shell uname -s)

MLX_PATH = ./MinilibX

SRCF = apply.c	draw.c			hooks.c	main.c	rot.c \
	   colo.c	handelfile.c	img.c	mouse.c

INC =-I ./inc/ -I ./libft/inc/
INCF = libft/inc/libft.h inc/fdf.h inc/keydef.h

SRC_DIR = src
OBJ_DIR = obj

ifeq ($(UNAME_S),Linux)
	LIBS += $(MLX_PATH)/libmlx.a -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	LIBS += -lmlx -framework OpenGL -framework AppKit
endif

SRCS = $(addprefix $(SRC_DIR)/,$(SRCF))
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCF:.c=.o))

txtblk=\e[0;30m
txtred=\e[0;31m # Red
txtgrn=\e[0;32m # Green
txtylw=\e[0;33m # Yellow
txtblu=\e[0;34m # Blue
txtpur=\e[0;35m # Purple
txtcyn=\e[0;36m # Cyan
txtwht=\e[0;37m # White
bldblk=\e[1;30m # Black - Bold
bldred=\e[1;31m # Red
bldgrn=\e[1;32m # Green
bldylw=\e[1;33m # Yellow
bldblu=\e[1;34m # Blue
bldpur=\e[1;35m # Purple
bldcyn=\e[1;36m # Cyan
bakblk=\e[40m
bakred=\e[41m   # Red
bakgrn=\e[42m   # Green
bakylw=\e[43m   # Yellow
bakblu=\e[44m   # Blue
bakpur=\e[45m   # Purple
bakcyn=\e[46m   # Cyan
bakwht=\e[47m   # White
txtrst=\e[0m

$(NAME) : dirmake $(OBJS)
	@printf "${bldylw}[COMPILED]${bldpur}%40s${txtrst}\n" "$(NAME)"
	@$(cc) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCF)
	@printf "${bldgrn}%s${txtwht}%40s${txtrst}\n" "[Compiling] " "$<"	
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

dirmake: $(MLX_PATH)
	@mkdir -p obj
	@printf "${bldpur}%40s\n${txtrst}" "COMPILING DEPENDANTS"
	@make -C libft

all: dirmake $(NAME) 

$(MLX_PATH):
	@git clone https://github.com/Rubzy0422/minilibx $(MLX_PATH);make -C $(MLX_PATH)

clean:
	@printf "${txtred}%40s${txtrst}\n" "[CLEANING]"
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -rf $(MLX_PATH)
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all
	@printf "${bldgrn}%40s${bldpur}%s${bldgrn}%s\n${txtrst}" "[ Recompiled" "$(NAME)!" "]"

.PHONY: clean fclean all re
