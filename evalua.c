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

float evalua(int** pedidos, int horizonte, int retraso){
	//Inicializacion de variables
	int i;
	int k;
	float J = 0;
	int *stock;
	int stockinicial=10;
	int *repartidos;
	float precio_med=0.7;
	float precio_alm=0.2;

	//Inicializacion de tablas
	stock= (int*) malloc(horizonte*sizeof(int));
	repartidos=(int*) malloc(horizonte*sizeof(int));
	
	stock[0]=stockinicial;

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
		}else{
			stock[k]=stock[k-1]+(*pedidos)[k]-repartidos[k];
		}
		if(stock[k]<=0){
			break;
		}
		J = J+precio_med*(*pedidos)[k]+precio_alm*stock[k];
	}		
	return J;
}
