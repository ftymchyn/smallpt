# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 12:28:37 by ftymchyn          #+#    #+#              #
#    Updated: 2018/03/19 12:28:39 by ftymchyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = smallpt
CC          = clang
CFLAGS      = -Wall -Wextra -Werror -O3

SRCS_DIR    = ./srcs
OBJS_DIR    = ./objs
HEADERS_DIR = ./includes

HEADERS     = smallpt.h typedefs.h
HEADERS    := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

SRCS        = main.c
SRCS       += initialize_sdl.c draw_picture.c wait_events.c
SRCS       += ray.c sphere.c initialize_scene.c intersect.c
SRCS       += dot.c v_len.c norm.c cross.c
SRCS       += check_error.c clamp.c to_int.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I ./includes
INCLUDES   += -I /Library/Frameworks/SDL2.framework/Headers
LIBRARIES   = -L. /Library/Frameworks/SDL2.framework/SDL2

TO_LINKING  = $(addprefix $(OBJS_DIR)/, $(OBJS)) $(INCLUDES) $(LIBRARIES)

VPATH       = $(SRCS_DIR) $(OBJS_DIR)
VPATH      += $(SRCS_DIR)/sdl_window $(SRCS_DIR)/secondary_fns $(SRCS_DIR)/math
VPATH      += $(SRCS_DIR)/scene

all         : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(TO_LINKING)
	@printf "\e[38;5;46m./$(NAME) SUCCESSFUL BUILD\e[0m\n"

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@printf "\e[38;5;46m$(OBJS_DIR)    FOLDER CREATED\e[0m\n"

$(OBJS)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES)

clean       :
	@rm -rf $(OBJS_DIR)
	@printf "\e[38;5;226m$(OBJS_DIR)    FOLDER DELETED\e[0m\n"

fclean      : clean
	@rm -f $(NAME)
	@printf "\e[38;5;226m./$(NAME) DELETED\e[0m\n"

re          : fclean all