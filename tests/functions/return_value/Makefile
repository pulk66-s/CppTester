##
## C++ Mocha Tester, 2023
## CppTester
## File description:
## Makefile for functions return value tests
##

CC			= g++
SRC			= ./int.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= bin
CFLAGS		= -W -Wall -Wextra

TESTSER		= CppTester
TESTS_SRC	= $(SRC) \
			./tests/testInt.cpp

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
