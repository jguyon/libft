#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#              #
#    Updated: 2017/02/06 04:31:25 by jguyon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Configuration variables
include config.mk
# Local overrides, should be excluded from version-control
-include local.mk

override CPPFLAGS := $(strip $(CPPFLAGS) -I$(INCLUDE_PATH) -MMD -MP)
override LDFLAGS := $(strip $(LDFLAGS) -L.)
override LDLIBS := $(strip $(LDLIBS) $(NAME:lib%.a=-l%))

SOURCES := $(foreach module,$(MODULES),$(filter $(module)/%,$(SOURCES)))

SRC := $(SOURCES:%=$(SOURCE_PATH)/%.c)
OBJ := $(SRC:%.c=$(BUILD_PATH)/%.o)
DEP := $(OBJ:%.o=%.d)

TST_SRC := $(TESTS:%=$(TEST_PATH)/%.c)
TST_CMN := $(TESTS_COMMON:%=$(TEST_PATH)/%.c)
TST_EXE := $(TST_SRC:%.c=$(BUILD_PATH)/%.t)
TST_DEP := $(TST_EXE:%.t=%.d)

PATHS := $(sort $(dir $(OBJ) $(TST_EXE)))

# Compile the release version of the library
all: $(NAME)

debug test: CFLAGS += $(DBGFLAGS)

# Compile the debug version of the library
debug: $(NAME)

# Compile and execute tests
test: $(TST_EXE)
	$(PROVE) $^

# Remove intermediate files
clean:
	-rm -f $(OBJ) $(DEP) $(TST_DEP)

# Remove library, tests and intermediate files
fclean: clean
	-rm -f $(NAME) $(TST_EXE)

# Recompile library
re: fclean all

.PHONY: all debug test clean fclean re

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_PATH)/%.o: %.c $(BUILD_PATH)/%.d | $(PATHS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@touch $@

$(BUILD_PATH)/%.t: %.c $(BUILD_PATH)/%.d $(TST_CMN) $(NAME) | $(PATHS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(filter %.c,$^) $(LDLIBS)
	@touch $@

$(BUILD_PATH)/%.d: ;

-include $(DEP) $(TST_DEP)

$(PATHS):
	@mkdir -p $@
