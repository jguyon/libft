#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#             *#
#*   Updated: 2016/12/09 18:42:57 by jguyon           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar

SRC_PATH = srcs
SRC_FILES = ft_memset.c														\
			ft_bzero.c														\
			ft_memcpy.c														\
			ft_memccpy.c													\
			ft_memmove.c													\
			ft_memchr.c														\
			ft_memcmp.c														\
			ft_strlen.c														\
			ft_strdup.c														\
			ft_strcpy.c														\
			ft_strncpy.c													\
			ft_strcat.c														\
			ft_strncat.c													\
			ft_strlcat.c													\
			ft_strchr.c														\
			ft_strrchr.c													\
			ft_strstr.c														\
			ft_strnstr.c													\
			ft_strcmp.c														\
			ft_strncmp.c													\
			ft_atoi.c														\
			ft_isalpha.c													\
			ft_isdigit.c													\
			ft_isalnum.c													\
			ft_isascii.c													\
			ft_isprint.c													\
			ft_toupper.c													\
			ft_tolower.c													\
																			\
			ft_memalloc.c													\
			ft_memdel.c														\
			ft_strnew.c														\
			ft_strdel.c														\
			ft_strclr.c														\
			ft_striter.c													\
			ft_striteri.c													\
			ft_strmap.c														\
			ft_strmapi.c													\
			ft_strequ.c														\
			ft_strnequ.c													\
			ft_strsub.c														\
			ft_strjoin.c													\
			ft_strtrim.c													\
			ft_strsplit.c													\
			ft_itoa.c														\
			ft_putchar_fd.c													\
			ft_putstr_fd.c													\
			ft_putendl_fd.c													\
			ft_putnbr_fd.c													\
			ft_putchar.c													\
			ft_putstr.c														\
			ft_putendl.c													\
			ft_putnbr.c														\
																			\
			ft_lstnew.c														\
			ft_lstdelone.c													\
			ft_lstdel.c														\
			ft_lstadd.c														\
			ft_lstiter.c													\
			ft_lstmap.c														\
			ft_lstfoldl.c													\
			ft_lstfoldr.c													\
			ft_lstsort.c

HDR_PATH = includes
HDR_FILES = libft.h

TEST_NAME = test_libft
TEST_PATH = tests

OBJ_PATH = objs
OBJ_FILES = $(SRC_FILES:%.c=%.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
HDR = $(addprefix $(HDR_PATH)/,$(HDR_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(HDR_PATH) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@make NAME=$(TEST_NAME) -C $(TEST_PATH)
	./$(TEST_PATH)/$(TEST_NAME)

.PHONY: all clean fclean re
