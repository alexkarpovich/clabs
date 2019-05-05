#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.c"

const int ARRAY_LENGTH = 10;

int main() {
    srand(time(NULL));   // Initialization, should only be called once. 
    int* arr = malloc(ARRAY_LENGTH * sizeof(int));
    printf("Original:\n"); 
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        arr[i] = rand() % 20;
        printf("%d ", arr[i]); 
    }

    quicksort(arr, ARRAY_LENGTH);

    printf("\nSorted:\n"); 
    for (int i = 0; i < 10 ; i++){ 
         printf("%d ", arr[i]); 
    } 
  
    return 0; 
}
