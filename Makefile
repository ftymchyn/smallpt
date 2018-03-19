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

HEADERS     = smallpt.h
SRCS        = main.c
OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
HEADERS    := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

INCLUDES    = -I ./includes
INCLUDES   += -I /Library/Frameworks/SDL2.framework/Headers
LIBRARIES   = -L. /Library/Frameworks/SDL2.framework/SDL2

all : $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBRARIES)
	@printf "\e[38;5;46m$(NAME) SUCCESSFUL BUILD\e[0m\n"

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@printf "\e[38;5;46m$(OBJS_DIR) FOLDER CREATED\e[0m\n"

$(OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	@rm -rf $(OBJS_DIR)
	@printf "\e[38;5;226m$(OBJS_DIR) FOLDER DELETED\e[0m\n"

fclean : clean
	@rm -f $(NAME)
	@printf "\e[38;5;226m$(NAME) DELETED\e[0m\n"

re : fclean all