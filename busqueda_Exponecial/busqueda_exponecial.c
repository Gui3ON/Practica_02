#include <stdio.h>
#include <stdlib.h>
#define min
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int exponentialSearch(int arr[], int n, int x);
int binarySearch(int arr[], int l, int r, int x);

int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int x=5;
	int result;
	int n=sizeof(arr)/sizeof(arr[0]);
	
	result = exponentialSearh(arr, n, x);
	if(result == -1){
		printf("Elemento no encontrado\n");
	}else{
		printf("Elemento se encuentra el la posicion %i",result);
	}
	return 0;
}

int exponentialSearch(int arr[], int n, int x)
{
 
    if (arr[0] == x){
        return 0;
	}

    int i = 1;
    while (i < n && arr[i] <= x){
        i = i*2;
  	}

    return binarySearch(arr, i/2, min(i, n-1), x);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == x){
            return mid;
    	}
  
        if (arr[mid] > x){
            return binarySearch(arr, l, mid-1, x);
  		
		}
        return binarySearch(arr, mid+1, r, x);
    }
  
    return -1;
}
