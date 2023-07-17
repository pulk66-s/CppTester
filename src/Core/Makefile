##
## C++ Mocha Tester, 2023
## Makefile
## File description:
## Compilation of the project Core
##

# Include of the global variables
include ./../../conf.mk

SRC			:= ./Core.cpp \
			./Params.cpp \
			./Compilation/Compilation.cpp \
			./Compilation/CompilFiles.cpp \
			./Compilation/CompilFlags.cpp \
			./Compilation/BuiltinFiles.cpp \
			./Compilation/Gpp.cpp \
			./Env.cpp

OBJ			:= $(SRC:.cpp=.o)

# Crash the compilation if no target is specified
all:
	@echo "$(COLOR_RED)No target specified.$(NO_COLOR)"
	exit 1

# Build the project
build: _build_message $(OBJ)

_build_message:
	@echo "$(COLOR_YELLOW)Building the project Core.$(NO_COLOR)"

# Cleaning all the project binaries
clean:
	@echo "$(COLOR_YELLOW)Cleaning the project Core.$(NO_COLOR)"
	$(RM) $(OBJ)

# Cleaning all the project binaries and the executable
fclean: clean
	@echo "$(COLOR_YELLOW)Full cleaning the project Core.$(NO_COLOR)"

# Cleaning all the project binaries and the executable, then build it
re: fclean build

# Build all the sources
%.o: %.cpp
	@echo "$(COLOR_GREEN)Compiling $<.$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@
