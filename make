posibilidades: posibilidades.o evalua.o funciones.o
	
	gcc	-W	-Wall	-c	evalua.c
	gcc	-W	-Wall	-c	posibilidades.c
	gcc	-W	-Wall	-c	funciones.c
	gcc -o OFH posibilidades.o funciones.o evalua.o
