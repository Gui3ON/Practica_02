//******************************************************************    
//OJEDA NAVARRO GUILLERMO
//Curso: Análisis y Diseño de algoritmos
//ESCUELA SUPERIOR DE CÓMPUTO - IPN
//Función de busqueda binaria   
//******************************************************************
// La función de búsqueda binaria recursiva. Vuelve
// la ubicación de x en el arreglo dado arr[0..N] está presente,
// de lo contrario regresa -1
#include <stdio.h>
int busquedaBinaria(int A[], int l, int N, int X) 
{
    int mid;
    
    if(N >= l)
    {
        mid = l + (N-l)/2; 
        // Si el elemento está presente en el medio
        // ya encontramos al elemanto y regresamos el elemento 
        // que esta en esta posición
        if (A[mid] == X)
        return mid;
        
        // Si el elemento es más pequeño que mid, entonces
        // solo puede estar presente en el subarreglo izquierdo
        if (A[mid] > X)
        return busquedaBinaria(A, l, mid - 1, X);
        
        // De lo contrario, el elemento solo puede estar presente
        // en el subarreglo derecho
        return busquedaBinaria(A,mid + 1, N, X);
    }

    // Llegamos aquí cuando el elemento no está
    // presente en la matriz
    return -1;
}



