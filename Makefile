
# Macros

CC = g++
OBJ = main.o dfa.o estado.o transicion.o

all: $(OBJ)
	$(CC) -std=c++14 -g -Wall -o dfa_simulation   $(OBJ)
	$(RM) $(OBJ) 
clean:
	$(RM) $(OBJ) dfa_simulation
main.o: main.cc
dfa.o :dfa.cc
estado.o :estado.cc
transicion.o: transicion.cc

