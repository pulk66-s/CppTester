##
## C++ Mocha Tester, 2023
## Makefile
## File description:
## Global Makefile of the project, used to compile the project.
##

# All global variables
include ./conf.mk

# Global Sources
SRC		:= $(SRC_DIR)/main.cpp

# Global Objects
OBJ		:= $(SRC:.cpp=.o)

# Redirect to build when no target is specified
all: build

# Build the project
# It launchs all the submakefiles that generates all .o
build: _build_message $(OBJ) submakefiles
	@echo "$(COLOR_YELLOW)Compiling every objects.$(NO_COLOR)"
	$(eval ALL_OBJ := $(shell find . -type f -name '*.o'))
	$(CC) $(CFLAGS) $(ALL_OBJ) -o $(NAME)
	@echo "$(COLOR_GREEN)Project built.$(NO_COLOR)"

_build_message:
	@echo "$(COLOR_YELLOW)Building all the project.$(NO_COLOR)"

submakefiles:
	@echo "$(COLOR_YELLOW)Building all the submakefiles.$(NO_COLOR)"
	@$(MAKE) -C $(CORE_DIR) build

# Cleaning all the project binaries
clean:
	@echo "$(COLOR_YELLOW)Cleaning all the project.$(NO_COLOR)"
	@$(MAKE) -C $(CORE_DIR) clean
	$(RM) $(OBJ)
	@echo "$(COLOR_GREEN)Project cleaned.$(NO_COLOR)"

# Cleaning all the project binaries and the executable
fclean: clean
	@echo "$(COLOR_YELLOW)Full cleaning all the project.$(NO_COLOR)"
	@$(MAKE) -C $(CORE_DIR) fclean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)Project fully cleaned.$(NO_COLOR)"

# Cleaning all the project binaries and the executable, then build it
re: fclean all

# Compile all the sources
%.o: %.cpp
	@echo "$(COLOR_GREEN)Compiling $<.$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@
