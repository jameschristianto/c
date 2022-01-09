CC = gcc
CFLAGS = -c -Wall
EXEC = -o "Hash Table"

MAIN = src\main.c
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) $(EXEC)
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN)