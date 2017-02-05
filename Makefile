#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#              #
#    Updated: 2017/02/05 02:16:14 by jguyon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra
LDFLAGS =
DEPFLAGS = -MMD -MP
TEST_CMD = prove -f
TEST_CFLAGS = -g -Wno-format
TEST_LDFLAGS = -g

NAME = libft.a

SOURCES = \
	memory/ft_memalloc \
	memory/ft_memdel \
	memory/ft_memchr \
	memory/ft_memcmp \
	memory/ft_memset \
	memory/ft_bzero \
	memory/ft_memcpy \
	memory/ft_memccpy \
	memory/ft_memmove \
	\
	strings/ft_strnew \
	strings/ft_strdel \
	strings/ft_strdup \
	strings/ft_strsub \
	strings/ft_strjoin \
	strings/ft_strtrim \
	strings/ft_strsplit \
	strings/ft_strlen \
	strings/ft_strnlen \
	strings/ft_strchr \
	strings/ft_strrchr \
	strings/ft_strchrnul \
	strings/ft_strstr \
	strings/ft_strnstr \
	strings/ft_strcmp \
	strings/ft_strncmp \
	strings/ft_strequ \
	strings/ft_strnequ \
	strings/ft_strclr \
	strings/ft_strcpy \
	strings/ft_strncpy \
	strings/ft_strcat \
	strings/ft_strncat \
	strings/ft_strlcat \
	\
	chars/ft_isalpha \
	chars/ft_isdigit \
	chars/ft_isalnum \
	chars/ft_isascii \
	chars/ft_isprint \
	chars/ft_toupper \
	chars/ft_tolower \
	\
	numbers/ft_atoi \
	numbers/ft_itoa \
	\
	unicode/ft_wcconv \
	unicode/ft_wclen \
	unicode/ft_wstrlen \
	\
	dlists/ft_dlst_init \
	dlists/ft_dlst_insertl \
	dlists/ft_dlst_insertr \
	dlists/ft_dlst_pushl \
	dlists/ft_dlst_pushr \
	dlists/ft_dlst_remove \
	dlists/ft_dlst_popl \
	dlists/ft_dlst_popr \
	dlists/ft_dlst_replace \
	dlists/ft_dlst_swap \
	dlists/ft_dlst_slice \
	dlists/ft_dlst_splicel \
	dlists/ft_dlst_splicer \
	dlists/ft_dlst_joinl \
	dlists/ft_dlst_joinr \
	dlists/ft_dlst_prev \
	dlists/ft_dlst_next \
	dlists/ft_dlst_first \
	dlists/ft_dlst_last \
	dlists/ft_dlst_empty \
	dlists/ft_dlst_singular \
	dlists/ft_dlst_foreachl \
	dlists/ft_dlst_foreachr \
	dlists/ft_dlst_foreachl_from \
	dlists/ft_dlst_foreachr_from \
	dlists/ft_dlst_sort \
	\
	streams/ft_std \
	streams/ft_fopencookie \
	streams/ft_setbuffer \
	streams/ft_fwrite \
	streams/ft_fputc \
	streams/ft_fputs \
	streams/ft_ferror \
	streams/ft_clearerr \
	streams/ft_fclose \
	streams/ft_fflush \
	\
	printf/ft_printf \
	printf/ft_vprintf \
	printf/ft_dprintf \
	printf/ft_vdprintf \
	printf/ft_sprintf \
	printf/ft_vsprintf \
	printf/ft_snprintf \
	printf/ft_vsnprintf \
	printf/ft_fprintf \
	printf/ft_vfprintf \
	printf/pf_parse_info \
	printf/pf_convert \
	printf/pf_convert_char \
	printf/pf_convert_str \
	printf/pf_convert_int \
	printf/pf_convert_uint \
	printf/pf_convert_ptr \
	printf/pf_uintmax_len \
	printf/pf_write_pad \
	printf/pf_write_str \
	printf/pf_write_wstr \
	printf/pf_write_uint \
	\
	tap/ft_tap_start \
	tap/ft_tap_end \
	tap/ft_tap_pass \
	tap/ft_tap_fail \
	tap/ft_tap_diag \
	tap/ft_tap_plan \
	tap/ft_tap_test \
	tap/ft_tap_ok \
	tap/ft_tap_notok \
	tap/ft_tap_ieq \
	tap/ft_tap_notieq \
	tap/ft_tap_ueq \
	tap/ft_tap_notueq \
	tap/ft_tap_seq \
	tap/ft_tap_notseq \
	tap/ft_tap_quote \

TESTS = \
	test_memory \
	test_strings \
	test_dlists \
	test_streams \
	test_printf \

TEST_UTILS = \
	common_main

SRC_PATH := srcs
TST_PATH := tests
INC_PATH := includes
BLD_PATH := build

OBJ := $(SOURCES:%=$(BLD_PATH)/%.o)
DEP := $(OBJ:%.o=%.d)

TST_OBJ := $(TESTS:%=$(BLD_PATH)/$(TST_PATH)/%.o)
TST_UTL := $(TEST_UTILS:%=$(BLD_PATH)/$(TST_PATH)/%.o)
TST_DEP := $(TST_OBJ:%.o=%.d) $(TST_UTL:%.o=%.d)
TST_EXE := $(TST_OBJ:%.o=%.t)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(BLD_PATH)/%.o: $(SRC_PATH)/%.c $(BLD_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(DEPFLAGS) -o $@ -c $<

test: CFLAGS += $(TEST_CFLAGS)
test: LDFLAGS += $(TEST_LDFLAGS)
test: $(TST_EXE)
	$(TEST_CMD) $^

$(BLD_PATH)/$(TST_PATH)/%.t: $(BLD_PATH)/$(TST_PATH)/%.o $(TST_UTL) $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) -o $@ $^

$(BLD_PATH)/$(TST_PATH)/%.o: $(TST_PATH)/%.c $(BLD_PATH)/$(TST_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_PATH) $(DEPFLAGS) -o $@ -c $<

.SECONDARY: $(TST_OBJ) $(TST_UTL)

$(BLD_PATH)/%.d: ;

-include $(DEP) $(TST_DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TST_OBJ) $(TST_UTL) $(TST_DEP) $(TST_EXE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re
