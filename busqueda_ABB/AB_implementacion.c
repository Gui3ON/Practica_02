#include <stdio.h>
#include <stdlib.h>

#define NODO struct nodo
// creacion del nodo
NODO{
	int dato;
	NODO *izq, *der,*padre;
};

NODO *raiz = NULL;
//inicializar el nodo con null
NODO *crear_nodo(int dato, NODO *hoja){
	NODO *nuevo = malloc(sizeof(NODO));
	nuevo->dato = dato;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	nuevo->padre = hoja;
	return nuevo;
}

void acomodar(int dato,NODO **raiz){
	if(*raiz != NULL){
		if(dato > (*raiz)->dato){
			//acomodar del lado derecho
			if((*raiz)->der){
				acomodar(dato, &(*raiz)->der);
			}else{
				(*raiz)->der = crear_nodo(dato, (*raiz)->der);
			}
		}else if(dato < (*raiz)->dato){
			//acomodar del lado izquierdo
			if((*raiz)->izq){
				acomodar(dato, &(*raiz)->izq);
			}else{
				(*raiz)->izq = crear_nodo(dato, (*raiz)->izq);
			}
		}else{
			printf("Valor duplicado, no se agregara al arbol\n");
		}
	}else{
		*raiz = crear_nodo(dato,*raiz);
	}
}
// busqueda del dato en cada hoja dependiendo su valor menor o mayor de la raiz
NODO *buscar(int dato,NODO *hoja){
	if(hoja){
		if(dato > hoja->dato){
			return buscar(dato, hoja->der);
		}else if(dato < hoja->dato){
			return buscar(dato, hoja->izq);
		}else hoja;
	}else{
		return NULL;
	}
}
//ordena el arbol de menor a mmayor
void orden (NODO *hoja){
	if(hoja){
		orden(hoja->izq);
		printf("%d\t", hoja->dato);
		orden(hoja->der);
	}
}

void eliminar(NODO *hoja){
	printf("Funcion no implementacio =(\n");
}
// llamada de cada operacion, ingreso de datos para el arbol y para la busqueda
void agregar_dato(void){
	int dato;
	printf("Ingrese dato:");
	scanf("%d",&dato);
	acomodar(dato, &raiz);
}

void buscar_dato(void){
	int dato;
	printf("Dato a buscar:");
	scanf("%d",&dato);
	NODO *resultado=buscar(dato, raiz);
	if(resultado){
		printf("dato encontrado en el arbol, en la dirreccion:%p\n",resultado);
	}else{
		printf("No se encontro en el arbol\n");
	}
}

void recorrer_arbol(){
	printf("Recorrer en orden\n");
	orden(raiz);
	printf("\n");
}

void eliminar_dato(){
	int dato;
	printf("Dato a eliminar:");
	scanf("%d",&dato);
	NODO *resultado=buscar(dato, raiz);
	if(resultado){
		eliminar(resultado);
	}else{
		printf("No se encontro en el arbol");
	}
}
// menu principal, inicializacion de cada operacion segun lo que el usuario requiera
int main(int argc,char **args){
	NODO *raiz = NULL;
	int opcion;
	do{
		printf("\tArbol Binario\n\n");
		printf("1)Agregar Elemento\n");
		printf("2)Buscar Elemento\n");
		printf("3)Recurrer el arbol\n");
		printf("4)Eliminar Elemento\n");		
		printf("5)Salir\n");
		printf("Tu opcion");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				agregar_dato();
				break;
			case 2:
				buscar_dato();
				break;
			case 3:
				recorrer_arbol();
				break;
			case 4:
				eliminar_dato();
				break;
		}
	}while(opcion!=5);
	
	return 0;
}
