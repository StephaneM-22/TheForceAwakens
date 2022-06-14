CC = g++
CFLAGS = -g -Wall

TARGET = main
SOURCE = main

PATH_LIB = ./biblioteca/
PATH_ALG = ./algoritimos/

LIB = $(PATH_LIB)combinacao.c $(PATH_LIB)planeta.c $(PATH_LIB)escolha_gulosa.c $(PATH_LIB)escolha_entrada.c $(PATH_LIB)matriz.c 

ALG = $(PATH_ALG)forca_bruta.c $(PATH_ALG)alg_guloso.c $(PATH_ALG)prog_dinamica.c 

all: $(TARGET).c 
	$(CC) $(CFLAGS) -o $(SOURCE) $(LIB) $(ALG) $(TARGET).c

clean: 
	$(RM) $(SOURCE) output.txt

//gcc main.c algoritimos/alg_guloso.c algoritimos/forca_bruta.c algoritimos/prog_dinamica.c biblioteca/combinacao.c biblioteca/escolha_entrada.c biblioteca/escolha_gulosa.c biblioteca/matriz.c biblioteca/planeta.c -o tp
