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

int bisiesto(int year);
//void obtenerMatrix(int filasMatrix,int TAM,int *matrixResult[][TAM], int *matrix1[filasMatrix][TAM], int numPedidos, int *vTamPedidos[]);

int main(int argc, char *argv[]){
	
	int TAM;
	int j;
	int i=0;
	int k;
	int n;
	int limite=1;
	int error=0;

	int numPedidos;
	int numDiasNo=argc-3;
	int diasMes;
	int aux=0;
	
	if (argc<3){
		error=1;
		printf("ERROR1:\nNumero de argumentos de la funcion incorrectos\n");
		printf("La llamada a la funcion debe ser \"%s\" \"numero de dias en el horizonte\" \"numero de pedidos en el horizonte\" \"OPCIONAL:fecha de dias de no pedido\":\n",argv[0]);
		printf("dd/mm/aaaa\n");
	}else{
		for(i=0;argv[1][i]!='\0';i++){
			if(argv[1][i]<'0'||argv[1][i]>'9'){
				error=2;
			}
		}
		if(error!=0){
			printf("ERROR2:\nValor de numero de dias en el horizonte incorrecto. Introduzca valor numerico\n");
		}else{
			
			TAM=atoi(argv[1]);
			for(i=0;argv[2][i]!='\0';i++){
				if(argv[2][i]<'0'||argv[2][i]>'9'){
					error=3;
				}
			}
			if(error!=0){
				printf("ERROR3:\nValor de numero de pedidos en el horizonte incorrecto. Introduzca valor numerico\n");
			}else{
						
				numPedidos=atoi(argv[2]);
				
				if(numPedidos>TAM){
					error=4;
					printf("ERROR4:\nNumero de dias de pedido mayor que dias en el horizonte\n");
				}else{
				//Inicializar vector diasNO
						int diasNO[TAM];
						for(i=0;i<TAM;i++){
							diasNO[i]=0;
						}
					if(argc>3){
						
						
	
						time_t t;
						struct tm *tm;
						char fechayhora[100];
						
						
						t=time(NULL);
						tm=localtime(&t);
						strftime(fechayhora, 100, "%d/%m/%Y", tm);
						j=0;
						k=0;
						char auxFecha[5];
						int FechaActual[3];
						for(i=0;fechayhora[i]!='\0';i++){
							auxFecha[k]=fechayhora[i];
							k++;
							if(fechayhora[i]=='/'){
								auxFecha[k]='\0';
								FechaActual[j]=atoi(auxFecha);
								j++;
								k=0;
							}
						}
						auxFecha[k]='\0';
						FechaActual[j]=atoi(auxFecha);
						j++;
						//Fecha introducida por linea de comandos
						k=0;
						int Fecha[numDiasNo][3];
						for(n=0;n<numDiasNo;n++){
							j=0;						
							k=0;	
							for(i=0;argv[n+3][i]!='\0';i++){
								if(argv[n+3][i]=='/'){
									auxFecha[k]='\0';
									Fecha[n][j]=atoi(auxFecha);
									j++;
									k=0;
								}else if(argv[n+3][i]<'0'||argv[n+3][i]>'9'){
									error=5;
								}else{
									auxFecha[k]=argv[n+3][i];
									k++;
								}
							}
							auxFecha[k]='\0';
							Fecha[n][j]=atoi(auxFecha);
						}	
						for(n=0;n<numDiasNo;n++){
							if(Fecha[n][1]>12||Fecha[n][1]<1){
								error=6;
							}else if(Fecha[n][0]<1){
								error=6;
							}switch (Fecha[n][1]){
								case 1:
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 2:
									if(bisiesto(Fecha[n][2])==1){
										diasMes=29;
										if(Fecha[n][0]>29){
											error=6;
										}
									}
									else{
										diasMes=28;
										if(Fecha[n][0]>28){
											error=6;
										}
									}
									break;
								case 3:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 4:
									diasMes=30;
									if(Fecha[n][0]>30){
										error=6;
									}
									break;
								case 5:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 6:
									diasMes=30;
									if(Fecha[n][0]>30){
										error=6;
									}
									break;
								case 7:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 8:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 9:
									diasMes=30;
									if(Fecha[n][0]>30){
										error=6;
									}
									break;
								case 10:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								case 11:
									diasMes=30;
									if(Fecha[n][0]>30){
										error=6;
									}
									break;
								case 12:
									diasMes=31;
									if(Fecha[n][0]>31){
										error=6;
									}
									break;
								default:
									error=6;
							}
							if(FechaActual[2]>Fecha[n][2]){ //Si el año es menor
								error=6;					//error
							}else{
								aux=Fecha[n][2]-FechaActual[2];	
								if(aux>1){	//si la diferencia de años es mayor que uno
									error=6;//error
								}else{
									if(FechaActual[1]>Fecha[n][1]){ //si el mes es pasado
										error=6;			//error
									}else{		//otro caso
										if (aux==1){ //Distinto año
										//	printf("Distinto año\n");
											if(!((Fecha[n][1]==1)&&(FechaActual[1]==12))){ //no es enero y diciembre
												error=6;		//error
											}else{ //Si lo son
												if(aux==1){ //Si son de meses diferentes
													if(FechaActual[0]+TAM-diasMes<Fecha[n][0]){//Fuera del horizonte
														error=6; //error
													}else{
														aux=diasMes-FechaActual[0];
														aux=aux+Fecha[n][0];
														diasNO[aux]=1;
													}
												}
											}
												
										}else{
											aux=Fecha[n][1]-FechaActual[1];
											if(aux>1){
												error=6;
											}else{ 
												if(aux==1){ //Si son de meses diferentes
													if(FechaActual[0]+TAM-diasMes-1<Fecha[n][0]){//Fuera del horizonte
														error=6; //error
													}else{
															aux=diasMes-FechaActual[0];
															aux=aux+Fecha[n][0];
															diasNO[aux]=1;
													}
													
												}else{//CASO del mismo mes
													if(FechaActual[0]>Fecha[n][0]){//Fecha antigua
														error=6;
													}else if(FechaActual[0]+TAM-1<Fecha[n][0]){//Fecha fuera del horizonte
														error=6;
													}else{
														aux=Fecha[n][0]-FechaActual[0];
														diasNO[aux]=1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					if (error==5){
						printf("Error=%d\n",error);
						printf("ERROR5:\nDias incorrectos. Utilizar la siguiente notacion:\n");
						printf("dd/mm/yyyy\n");
					}else if(error==6){
						printf("ERROR6:\nFecha incorrecta fuera del horizonte\n");
					}else{

						for(j=0;j<TAM;j++){
							limite=limite*2;
						}
						
						int cambio=1;


						//Reserva de memoria para matrix1
						int **matrix1;
						
						matrix1=(int **) malloc(limite*sizeof(int*));
						for(i=0;i<limite;i++){
							matrix1[i]=(int *) malloc(TAM*sizeof(int));
						}

						//Inicializamos el primer vector a 0
						for (j=0;j<TAM;j++){
							matrix1[0][j]=0;
						}

						//Bucle de llene de la matriz

						for (i=1;i<limite;i++){
							if(matrix1[i-1][TAM-1]==0){ //Alternancia del primer bit
								matrix1[i][TAM-1]=1;
							}else{
								matrix1[i][TAM-1]=0;
							}
							for(j=TAM-2;j>=0;j--){
								cambio=1;
								for(k=TAM-1;k>j;k--){
									if(matrix1[i-1][k]==0){
										cambio=0;
									}
								}

								if(matrix1[i-1][j]==0&&cambio==1){
									matrix1[i][j]=1;
								}else if(matrix1[i-1][j]==1&&cambio==1){
									matrix1[i][j]=0;
								}else{
									matrix1[i][j]=matrix1[i-1][j];
								}
							}
						}
						//Matriz de pedidos	quitando dias NO posibles						
						int **matrix;
						
						matrix=(int **) malloc(limite*sizeof(int*));
						for(i=0;i<limite;i++){
							matrix[i]=(int *) malloc(TAM*sizeof(int));
						}
						
						for(i=0;i<limite;i++){
							for(j=0;j<TAM;j++){
								matrix[i][j]=matrix1[i][j];
								if(diasNO[j]==1){
									matrix[i][j]=0;
								}
							}
						}

						int guardar;
						k = 0;
					
						for(i=0;i<limite;i++){
							guardar=1;
							for(j=1;j<TAM;j++){
								if(matrix[i][j-1]==1&&matrix[i][j]==1){
									guardar=0;
								}
							}
							if(guardar==1){
								for(j=0;j<TAM;j++){
									matrix1[k][j]=matrix[i][j];
								}
								k++;
							}
						}
						int filasPedidos=k;
					
						int h=0;
						int auxIguales=0;

						for(i=0;i<filasPedidos;i++){
							guardar=1;
							for(k=0;k<i;k++){
								auxIguales=0;
								for(j=0;j<TAM;j++){
									if(matrix1[k][j]==matrix1[i][j]){
										auxIguales++;
									}
								}
								if(auxIguales==TAM){
									guardar=0;
								}
							}
							if(guardar==1){
								for(j=0;j<TAM;j++){
									matrix[h][j]=matrix1[i][j];
								}
								h++;
							}
						}
						filasPedidos=h;
					//	printf("Matriz sin semanas repetidas con numero de pedidos solicitados\n");
					
						k=0;
						for(i=0;i<filasPedidos;i++){
							guardar=1;
							int auxNumPedidos=0;
							for(j=0;j<TAM;j++){
								if(matrix[i][j]==1){
									auxNumPedidos++;
								}
							}
							if(auxNumPedidos!=numPedidos){
								guardar=0;
							}
							if(guardar==1){
							//	printf("%d->\t",k);
								for(j=0;j<TAM;j++){
									matrix1[k][j]=matrix[i][j];
								//	printf("%d",matrix1[k][j]);
								}
							//	printf("\n");
								k++;
							}
						}
						filasPedidos=k;
					//	printf("Numero de posibilidades final: %d\n",filasPedidos);
						
						//Una vez obtenidas las posibilidades de salida, obtener combinaciones con cuatro valores ejemplo: 1, 5, 7, 12.
						int nTamPedidos=4;
						int vTamPedidos[]={1,5,7,12};
						int g=0;
						h=0;
						n=0;
						
					//	printf("Matriz base de combinaciones\n");
						int exp4=1;
						//Obtenemos primero el numero de combinaciones posibles								
						for(i=0;i<numPedidos;i++){
							exp4=exp4*nTamPedidos;
						}
						
						int divisor = exp4/nTamPedidos; //Variable auxiliar para acceder al vector de la forma adecuada
						//Matriz de combinaciones
						int **matrixAux1;
						
						matrixAux1=(int **) malloc(exp4*sizeof(int*));
						for(i=0;i<exp4;i++){
							matrixAux1[i]=(int *) malloc(numPedidos*sizeof(int));
						}
						
						
						for(j=0;j<numPedidos;j++){	//Luego por filas
							for(i=0;i<exp4;i++){	//Primero por columnas
								matrixAux1[i][j]=vTamPedidos[(i/divisor)%nTamPedidos];
							}
							divisor=divisor/nTamPedidos;	//Disminuimos la auxiliar para acceder a la posicion correcta
						}

						for(i=0;i<exp4;i++){		//Imprimimos la matriz
							for(j=0;j<numPedidos;j++){
							//	printf("%d",matrixAux1[i][j]);	
							}
						//	printf("\n");
						}

					//	printf("Numero de posibilidades total: %d\n",filasPedidos*exp4);
						
						//Matriz definitiva
						free(matrix);
						matrix=NULL;
						
						matrix=(int **) malloc(filasPedidos*exp4*sizeof(int*));
						for(i=0;i<filasPedidos*exp4;i++){
							matrix[i]=(int *) malloc(TAM*sizeof(int));
						}
						
						
						// Bucles para la obtencion de la matriz definitiva
						for(i=0;i<filasPedidos;i++){	// Por cada fila de la matriz de dias de pedidos y no
							for(k=0;k<exp4;k++){		// Accedemos todas las veces de las combinaciones posibles
								for(j=0;j<TAM;j++){		// En el recorrido
									if(matrix1[i][j]==1){	// Si es 1 se cambia por el valor correspondiente
										matrix[n][j]=matrix1[i][j]*matrixAux1[k][g];
										g++;
										
									}else{	//Si es 0 se deja igual
										matrix[n][j]=matrix1[i][j];
									}							
								}
								g=0;	//Al finalizar cada pasada reiniciamos el contador g a 0
								n++;	//Y pasamos a rellenar la siguiente fila
							}
						}
						
						filasPedidos=n;		
						// Imprimimos por pantalla todas las posibilidades				
						
						printf("Matriz posibilidades:\n");
						for(i=0;i<filasPedidos;i++){
							printf("%d->\t",i);
							for(j=0;j<TAM;j++){
								printf("%d",matrix[i][j]);
							}
							printf("\n");
						}
						printf("Filas de pedido: %d\n",filasPedidos);
						//Liberamos espacio ocupado de forma inutil
						free(matrix1);
						matrix1=NULL;
						free(matrixAux1);
						matrixAux1=NULL;
						// Una vez obtenidas todas las posibles combinaciones
						// para un determinado horizonte, procedemos al cálculo
						// y consiguiente obtención de los días de pedidos
						// útiles para el farmaceútico
						/* evalua(int** pedidos, int horizonte, int retraso, int ** stock) */
						int x;
						float J = 1000;
						float Jmin = 1000;
						int *stock=(int*) malloc(TAM*sizeof(int));
						int *stockOptimo=(int*) malloc(TAM*sizeof(int));
						int *vectorOptimo=(int*) malloc(TAM*sizeof(int));
						for(x=0; x<filasPedidos; x++){
							J = evalua(&matrix[x], TAM, 0, &stock);
							printf("%d->\tJ = %f\n",x,J);
							if(J <Jmin){
								Jmin = J;
								for(k=0; k<TAM; k++){
									vectorOptimo[k]=matrix[x][k];
									stockOptimo[k]=stock[k];
								}
							}
						}
						printf("Jmin= %f\nVector Óptimo de pedido:", Jmin);
						for(x=0;x<TAM; x++){
							printf("%d",vectorOptimo[x] );
						}
						printf("\nStock del pedido óptimo:");
						for(x=0;x<TAM; x++){
							printf("%d",stockOptimo[x] );
						}
						printf("\n");
					}
				}
			}
		}
	}	
	//printf("\n");
	
	
	return error;
}

int bisiesto(int year){
	int bis;
	bis=(year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	return bis;
}
