#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#              #
#    Updated: 2017/01/02 00:01:52 by jguyon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra

NAME = ./libft.a

SRC_PATH = ./srcs
INC_PATH = ./includes
OBJ_PATH = ./objs
DEP_PATH = ./deps

SRC = $(wildcard $(SRC_PATH)/*.c) $(wildcard $(SRC_PATH)/*/*.c)
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
DEP = $(SRC:$(SRC_PATH)/%.c=$(DEP_PATH)/%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEP_PATH)/%.d
	@mkdir -p $(dir $(OBJ_PATH)/$*) $(dir $(DEP_PATH)/$*)
	$(CC) $(CFLAGS) -I$(INC_PATH) -MMD -MP -MF $(DEP_PATH)/$*.d -o $@ -c $<

$(DEP_PATH)/%.d: ;

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
