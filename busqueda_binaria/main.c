//*****************************************************************
//OJEDA NAVARRO GUILLERMO
//Curso: Análisis y Diseño de algoritmos
//ESCUELA SUPERIOR DE CÓMPUTO - IPN
//Implementación simple de busqueda binaria
//Compilación: ""gcc tiempo.c main.c busqueda_binaria.c -o busqueda_binaria"
//Ejecución: "./buqueda_binaria 4 4000""

//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************



//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
int cargarNum(int *A, int N);
int busquedaBinaria(int A[], int l, int N, int X); 
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i,j,k; 	//Variables auxiliares para loops
	int * A= NULL; // Apuntador para el arreglo dinámico
	int resultado;
	int N=0, X=0;	
	//********************************************************************************
	//Obtener el número a buscar
	//********************************************************************************
	if (argc<2) 
	{
		printf("Indique el número que se buscara - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
		exit(-1);
	}  
	X=atoi(argv[1]); // Número a buscar
	//***************************************************************************************************************************
	//Saber cuál es el tamaño del problema N
	//***************************************************************************************************************************	
	//Si no se introduce correctamente N
	if (argc!=3) 
	{
		printf("\nIndique el tamaño de N  \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[2]);
	//******************************************************************	
	//Crear arreglo dinámico
	//******************************************************************		
 	 A = malloc(N * sizeof(int));
  
	 if(A ==  NULL)
	  {
	    printf("Memoria no disponible");
	    exit(0);
	  }
	//******************************************************************	
	//Llenar el arreglo donde se buscara X con N cantidad de numeros 
	//******************************************************************	
	
	cargarNum(A,N);
	
	/*
	printf("\n%d\n", X);
	for(i=0; i< N; i++)
    {
      printf("\t%d\n", A[i]);
    }
    printf("\n%d\n", X);
   */

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Iniciar busqueda binaria
	//******************************************************************
	resultado = busquedaBinaria(A, 0, N - 1, X);
    if(resultado == -1)
    {
    	printf("Numero %d no esta prensente en el arreglo", X);
    }
    else
    {
    	printf("Numero %d encontrado", X);
    }	
   

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("REAL (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	free(A);
	//Terminar programa normalmente	
	exit (0);	
}
//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
int cargarNum(int * A, int N)
{
//******************************************************************	
//Variables de cargarNum
//******************************************************************	
  int i;
  FILE * p_arch;
//******************************************************************	
//Abrir archivo numero.txt
//******************************************************************	   
    p_arch = fopen("10millones.txt","r");
//******************************************************************	
//Llenar el arreglo dinámico con los datos leidos en "numero.txt"
//******************************************************************	
    for(i=0; i< N; i++)
    {
      fscanf(p_arch, "%d", &A[i]);
    }
    fclose(p_arch); 
}
