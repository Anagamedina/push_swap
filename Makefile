# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 19:21:23 by anamedin          #+#    #+#              #
#    Updated: 2024/07/25 19:25:03 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
#----------------------------------------
RM = rm -rf
HEADER_DIR = includes
HEADER = $(HEADER_DIR)/push_swap.h
SRC_DIR  = src
#----------------------------------------
SRCS:= $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)
#----------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
#----------------------------------------
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
#---------------------------------------
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: all

.PHONY: all clean fclean re
