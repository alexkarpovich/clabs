#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.c"

const long long ARRAY_LENGTH = 99999999;

int main() 
{
    int ret = 0;
    long long* arr;
    srand(time(NULL));
    
    if (NULL == (arr = malloc(ARRAY_LENGTH * sizeof(long long)))) {
        ret = errno;
        goto exit;
    }

    for (long long i = 0; i < ARRAY_LENGTH; i++) {
        long long x = random();
        arr[i] = x;
    }

    quicksort(arr, ARRAY_LENGTH);
    
    exit:
        free(arr);
        return ret; 
}
