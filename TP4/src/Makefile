CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2

ALL = main operator.o fichier.o liste.o calcule factorielle chercherfichier etudiant_bd

.PHONY: all clean

all: $(ALL)

main: main.c operator.o fichier.o liste.o
	$(CC) $(CFLAGS) -o main main.c operator.o fichier.o liste.o

operator.o: operator.c operator.h
	$(CC) $(CFLAGS) -c operator.c

fichier.o: fichier.c fichier.h
	$(CC) $(CFLAGS) -c fichier.c

liste.o: liste.c liste.h
	$(CC) $(CFLAGS) -c liste.c

calcule: calcule.c operator.o
	$(CC) $(CFLAGS) -o calcule calcule.c operator.o

factorielle: factorielle.c
	$(CC) $(CFLAGS) -o factorielle factorielle.c

chercherfichier: chercherfichier.c
	$(CC) $(CFLAGS) -o chercherfichier chercherfichier.c

etudiant_bd: etudiant_bd.c fichier.o
	$(CC) $(CFLAGS) -o etudiant_bd etudiant_bd.c fichier.o

clean:
	rm -f *.o $(ALL)
