#include <stdio.h>
#include <stdlib.h>
int busquedafibo(int A[], int X, int N);
int busquedafibo(int A[], int X, int N)
{
   
    int fibMMm2 = 0;               
    int fibMMm1 = 1;               
    int fibM = fibMMm2 + fibMMm1;  

  
    while (fibM < N)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    
    int offset = -1;

   
    while (fibM > 1)
    {
       
        int i = ((offset + fibMMm2) < (N - 1)) ? (offset + fibMMm2) : (N - 1);

        if (A[i] < X)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (A[i] > X)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

     
        else
            return i;
    }

 
    if (fibMMm1 && A[offset + 1] == X)
        return offset + 1;

   
    return -1;
}
