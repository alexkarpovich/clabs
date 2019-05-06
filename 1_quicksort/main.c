#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qsort.h"

const long ARRAY_LENGTH = 99999999;

int main(int argc, char **argv) 
{
    int ret = 0;
    long* arr;
    srand(time(NULL));
    
    if (NULL == (arr = malloc(ARRAY_LENGTH * sizeof(long)))) {
        ret = errno;
        goto exit;
    }

    for (long i = 0; i < ARRAY_LENGTH; i++) {
        long x = random();
        arr[i] = x;
    }

    TEMPLATE(qsort,long)(arr, ARRAY_LENGTH);
    
    exit:
        free(arr);
        return ret; 
}
