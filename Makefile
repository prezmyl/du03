# Projekt: DU3
# Autor:   Přemysl Poláš
# Datum:   16.11.2023

CC = g++
CFLAGS = -Wall -Wextra -pedantic -g
 
main: main.o HashTable.o 
	$(CC) $(CFLAGS) -o main main.o HashTable.o 
