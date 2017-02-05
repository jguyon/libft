#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#              #
#    Updated: 2017/02/05 15:38:01 by jguyon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

include config.mk

SRC_PATH := srcs
TST_PATH := tests
INC_PATH := includes
BLD_PATH := build

OBJ := $(SOURCES:%=$(BLD_PATH)/%.o)
DEP := $(OBJ:%.o=%.d)

TST_OBJ := $(TESTS:%=$(BLD_PATH)/$(TST_PATH)/%.o)
TST_CMN := $(TESTS_COMMON:%=$(BLD_PATH)/$(TST_PATH)/%.o)
TST_DEP := $(TST_OBJ:%.o=%.d) $(TST_CMN:%.o=%.d)
TST_EXE := $(TST_OBJ:%.o=%.t)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $@ $^

$(BLD_PATH)/%.o: $(SRC_PATH)/%.c $(BLD_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_PATH) -MMD -MP -o $@ -c $<

test: CFLAGS += $(TEST_CFLAGS)
test: LDFLAGS += $(TEST_LDFLAGS)
test: $(TST_EXE)
	$(TEST_CMD) $^

$(BLD_PATH)/$(TST_PATH)/%.t: $(BLD_PATH)/$(TST_PATH)/%.o $(TST_CMN) $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) -o $@ $^

$(BLD_PATH)/$(TST_PATH)/%.o: $(TST_PATH)/%.c $(BLD_PATH)/$(TST_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_PATH) -MMD -MP -o $@ -c $<

.SECONDARY: $(TST_OBJ) $(TST_CMN)

$(BLD_PATH)/%.d: ;

-include $(DEP) $(TST_DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TST_OBJ) $(TST_CMN) $(TST_DEP) $(TST_EXE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re
