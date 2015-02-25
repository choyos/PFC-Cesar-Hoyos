posibilidades: posibilidades.o evalua.o
	
	gcc	-W	-Wall	-c	evalua.c
	gcc	-W	-Wall	-c	posibilidades.c
	gcc -o OFH posibilidades.o evalua.o
