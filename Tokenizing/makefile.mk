CC = gcc
CFLAGS = -c -Wall

MAIN = src\main.c
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) -o "Tokenizing"
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN)