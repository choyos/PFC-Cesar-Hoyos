/*  Proyecto fin de carrera*/
/* Optimizacion del stock de farmacos en hospitales*/
/* Fecha: 2014-2015*/
/*Apellidos: Hoyos Martín
Nombre: César*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"
#include <time.h>
#include "fechas.h"

#define LUNES 0
#define MARTES 1
#define MIERCOLES 2
#define JUEVES 3
#define VIERNES 4
#define SABADO 5
#define DOMINGO 6

#define TAM_BUF 100

void compruebaFecha(){

}

int bisiesto(int year){
	int bis;
	bis=(year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	return bis;
}

void obtieneFechasPedidos(int*v, int tam){
	int x;
	for(x=0; x<tam; x++){
		if(v[x]!=0){
			printf("Día: %d",x+1);
			printf("\tPedido: %d\n", v[x]);
			fechaPedido(x);
		}
	}
}


void fechaPedido(int dia){
	//Obtenemos hoy
	time_t t;
	struct tm *tm;
	char fechayhora[100];
	
	
	t=time(NULL);
	tm=localtime(&t);

	//Al día de hoy le añadimos los días en los que se pide
}