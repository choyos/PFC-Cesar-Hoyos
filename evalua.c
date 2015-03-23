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
	int stockinicial=4;
	int stock_min=3;
	int *repartidos;
	int *orders;
	float precio_med=0.7;
	float precio_alm=0.2;
	float coste_pedido= 0.1; //Coste de realizar un pedido
	float coste_recogida= 0.4; //Coste de almacenar el producto cuando llega
	float coste_sin_stock=10; //Coste asociado a quedarse sin stock y tener que recurrir a otro hospital
	float coste_oportunidad=0.9; //Coste asociado a poder haber realizado una inversión con el dinero del stock parado


	//Inicializacion de tablas
	repartidos=(int*) malloc(horizonte*sizeof(int));
	orders=(int*) malloc(horizonte*sizeof(int));

	/*
		Inicializa el vector de repartidos a todo 1
	*/
	for(i=0;i<horizonte;i++){
		repartidos[i]=1;
		if(pedidos[i]!=0){
			orders[i]=1;
		}
	}
	
	//Calculo de restricciones

	//Calculo de J y stock
	for(k=0;k<horizonte;k++){
		if(k==0){
			stock[k]=stockinicial;
		//	printf("%d\n",*stock[k] );
		}else{
			stock[k]=stock[k-1]+pedidos[k-retraso]-repartidos[k];
		}

		/* 
			Tenemos en cuenta la restricción de que el stock 
			no puede ser menor a una cantidad dada.
		*/
		if((stock[k])<stock_min){
			J=1000;
			break;
		}
		J = J+precio_med*pedidos[k]+(precio_alm+coste_oportunidad)*stock[k]+(coste_pedido+coste_recogida)*orders[k];
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


void fechaPedido(int dia){
	//Obtenemos hoy
	time_t t;
	struct tm *tm;
	char fechayhora[100];
	
	
	t=time(NULL);
	tm=localtime(&t);

	//Al día de hoy le añadimos los días en los que se pide

}