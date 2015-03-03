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
#include "evalua.h"

#define LUNES 0
#define MARTES 1
#define MIERCOLES 2
#define JUEVES 3
#define VIERNES 4
#define SABADO 5
#define DOMINGO 6

float evalua(int* pedidos, int horizonte, int retraso, int* stock){
	//Inicializacion de variables
	int i;
	int k;
	float J = 0;
	int stockinicial=10;
	int *repartidos;
	float precio_med=0.7;
	float precio_alm=0.2;

	//Inicializacion de tablas
	repartidos=(int*) malloc(horizonte*sizeof(int));

	/*
		Inicializa el vector de repartidos a todo 1
	*/
	for(i=0;i<horizonte;i++){
		repartidos[i]=1;
	}
	
	//Calculo de J y stock
	for(k=0;k<horizonte;k++){
		if(k==0){
			stock[k]=stockinicial;
		//	printf("%d\n",*stock[k] );
		}else{
			stock[k]=stock[k-1]+pedidos[k]-repartidos[k-retraso];
		}
		if((stock[k])<0){
			J=1000;
			break;
		}
		J = J+precio_med*pedidos[k]+precio_alm*stock[k];
	}		
	return J;
}
void inicializa(int * v,int tam){
	int x;
	for(x=0; x<tam;x++){
		v[x]=0;
	}
}

void obtieneFechasPedidos(int*v, int tam){
	int x;
	for(x=0; x<tam; x++){
		if(v[x]!=0){
			printf("Día: %d",x);
			printf("\tPedido: %d\n", v[x]);
			fechaPedido(x);
		}
	}
}

fechaPedido(int dia){
	//Obtenemos hoy
	time_t t;
	struct tm *tm;
	char fechayhora[100];
	
	
	t=time(NULL);
	tm=localtime(&t);
}