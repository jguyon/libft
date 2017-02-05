#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyon <jguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:56 by jguyon            #+#    #+#              #
#    Updated: 2017/02/05 19:59:12 by jguyon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Configuration variables
include config.mk
# Local overrides, should be excluded from version-control
-include local.mk

SRC := $(foreach module,$(MODULES),$(filter $(module)/%,$(SOURCES)))

OBJ := $(SRC:%=$(BUILD_PATH)/%.o)
DEP := $(OBJ:%.o=%.d)

DBG_OBJ := $(SRC:%=$(DEBUG_PATH)/%.o)
DBG_DEP := $(DBG_OBJ:%.o=%.d)

TST_OBJ := $(TESTS:%=$(DEBUG_PATH)/$(TEST_PATH)/%.o)
TST_CMN := $(TESTS_COMMON:%=$(DEBUG_PATH)/$(TEST_PATH)/%.o)
TST_DEP := $(TST_OBJ:%.o=%.d) $(TST_CMN:%.o=%.d)
TST_EXE := $(TST_OBJ:%.o=%.t)

define objs
$(filter %.o,$(1))
endef
define libs
$(patsubst lib%.a,-l%,$(filter lib%.a,$(1)))
endef

# Compile the release version of the library
all: $(NAME)

# Compile the debug version of the library
debug: $(DEBUG_NAME)

# Compile and execute tests
test: $(TST_EXE)
	$(TEST_CMD) $^

# Remove intermediate files
clean:
	rm -f $(OBJ) $(DEP) $(DBG_OBJ) $(DBG_DEP) $(TST_OBJ) $(TST_CMN) $(TST_DEP)

# Remove library, tests and intermediate files
fclean: clean
	rm -f $(NAME) $(DEBUG_NAME) $(TST_EXE)

# Recompile library
re: fclean all

.PHONY: all debug test clean fclean re

$(NAME): $(OBJ)
	$(AR) rcsu $@ $^

$(DEBUG_NAME): $(DBG_OBJ)
	$(AR) rcsu $@ $^

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.c $(BUILD_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -MMD -MP -o $@ -c $<

$(DEBUG_PATH)/$(TEST_PATH)/%.t: \
		$(DEBUG_PATH)/$(TEST_PATH)/%.o $(TST_CMN) \
		$(DEBUG_NAME)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $(call objs,$^) -L. $(call libs,$^)

$(DEBUG_PATH)/$(TEST_PATH)/%.o: $(TEST_PATH)/%.c $(DEBUG_PATH)/$(TEST_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_PATH) -MMD -MP -o $@ -c $<

$(DEBUG_PATH)/%.o: $(SOURCE_PATH)/%.c $(DEBUG_PATH)/%.d
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_PATH) -MMD -MP -o $@ -c $<

$(BUILD_PATH)/%.d: ;
$(DEBUG_PATH)/%.d: ;

-include $(DEP) $(DBG_DEP) $(TST_DEP)

.SECONDARY: $(TST_OBJ) $(TST_CMN)
