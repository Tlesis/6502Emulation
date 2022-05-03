CC=g++
CFLAGS=-Wall -g -std=c++17
WARN=-pedantic -Wextra -Werror -Wshadow -Wsign-conversion
NAME=6502

OFILES=main.o cpu.o

all: main

# Compiles object files into one binary
main: main.o include/cpu.o
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME).out

# Compile with all warnings
warn: main.o_Warn include/cpu.o_Warn
	$(CC) $(OFILES) -o $(NAME).out

# Makes .o object files
%.o: %.cpp
	$(CC) -O3 $(CFLAGS) -c $^

# Makes .o object files with all warnings
%.o_Warn: %.cpp
	$(CC) -O3 $(CFLAGS) $(WARN) -c $^

test: test.o
	$(CC) $(CFLAGS) test.o -o test.out

# Removes Compiled files
clean:
	@echo Cleaning. . .
	rm *.out *.o

# Compiles the project & runs the binary
run: main
	./$(NAME).out