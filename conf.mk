##
## C++ Mocha Tester, 2023
## CppTester
## File description:
## Makefile configuration for any child Makefile
##

# Printing variables
export COLOR_RED 		:= $$(printf '\033[0;31m')
export COLOR_GREEN 		:= $$(printf '\033[0;32m')
export COLOR_YELLOW		:= $$(printf '\033[0;33m')
export NO_COLOR			:= $$(printf '\033[0m')

## C++ Compiler Datas
export CC				:= g++
export CFLAGS			:= -Wall -Wextra -Werror -std=c++17
export C_DEBUG_FLAGS	:= $(CFLAGS) -g3 -fsanitize=address

## Directories
export SRC_DIR			:= ./src
export CORE_DIR			:= $(SRC_DIR)/Core

## Executable name
export NAME				:= CppTester