##
## C++ Mocha Tester, 2023
## CppTester
## File description:
## Makefile for binary memory tests
##

CC			= g++
SRC			= ./basicMemoryTest.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= bin
CFLAGS		= -W -Wall -Wextra

TESTSER		= CppTester
TESTS_SRC	= $(SRC)

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run_tests:
	$(TESTSER) $(TESTS_SRC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
