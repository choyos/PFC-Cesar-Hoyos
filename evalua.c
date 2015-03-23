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
#include "fechas.h"

#define LUNES 0
#define MARTES 1
#define MIERCOLES 2
#define JUEVES 3
#define VIERNES 4
#define SABADO 5
#define DOMINGO 6

#define TAM_BUF 100

float evalua(int* pedidos, int horizonte, int retraso, int* stock, int* repartidos){
	//Inicializacion de variables
	int k;
	float J = 0;
	int stockinicial=4;
	int stock_min=1;
	int *orders;
	float precio_med=0.7;
	float precio_alm=0.2;
	float coste_pedido= 0.1; //Coste de realizar un pedido
	float coste_recogida= 0.4; //Coste de almacenar el producto cuando llega
	float coste_sin_stock=10; //Coste asociado a quedarse sin stock y tener que recurrir a otro hospital
	float coste_oportunidad=0.9; //Coste asociado a poder haber realizado una inversión con el dinero del stock parado


	//Inicializacion de tablas
	orders=(int*) malloc(horizonte*sizeof(int));

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
			J=1000*coste_sin_stock;
			break;
		}
		J = J+precio_med*pedidos[k]+(precio_alm+coste_oportunidad)*stock[k]+(coste_pedido+coste_recogida)*orders[k];
	}

	
	free(orders);		
	return J;
}


void inicializa(int * v,int tam){
	int x;
	for(x=0; x<tam;x++){
		v[x]=0;
	}
}

