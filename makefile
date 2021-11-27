CC=gcc
MAIN=main.o
FUNCTIONS=my_mat.o
FLAGS= -Wall -g

all: connections

connections: $(MAIN) $(FUNCTIONS)
	$(CC) $(FLAGS) -o connections $(MAIN) $(FUNCTIONS) -lm


functions.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c -lm


main.o: main.c my_mat.h  
	$(CC) $(FLAGS) -c main.c -lm


.PHONY: clean

clean:
	rm -f main.o my_mat.o connections