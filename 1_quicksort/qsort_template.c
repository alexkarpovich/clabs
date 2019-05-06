
#ifdef T    
#include "templates.h"    
long TEMPLATE(partition, T) (T* arr, long len)  
{
    T pivot = arr[0];    
    long lidc = 1;
    long ridc = len - 1;

    while (1) {
        while (lidc <= ridc && arr[lidc] <= pivot) ++lidc;
        while (ridc >= lidc && arr[ridc] >= pivot) --ridc;

        if (lidc > ridc) {
            break;
        }

        T tmp = arr[lidc];
        arr[lidc] = arr[ridc];
        arr[ridc] = tmp;        
    }

    arr[0] = arr[ridc];
    arr[ridc] = pivot; 

    return ridc;
}

void TEMPLATE(qsort, T) (T* arr, long len) 
{
    if (len < 2) {
        return;
    }
    
    long sid = TEMPLATE(partition, T)(arr, len);

    TEMPLATE(qsort, T)(arr, sid);
    TEMPLATE(qsort, T)(arr+sid+1, len-sid-1);
}
#endif
