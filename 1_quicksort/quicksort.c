
int partition(long long* arr, long long len) {
    long long pivot = arr[0];    
    long long lidc = 1;
    long long ridc = len - 1;

    while (1) {
        while (lidc <= ridc && arr[lidc] <= pivot) ++lidc;
        while (ridc >= lidc && arr[ridc] >= pivot) --ridc;

        if (lidc > ridc) {
            break;
        }

        long long tmp = arr[lidc];
        arr[lidc] = arr[ridc];
        arr[ridc] = tmp;        
    }

    arr[0] = arr[ridc];
    arr[ridc] = pivot; 

    return ridc;
}

void quicksort(long long* arr, long long len) {
    if (len < 2) {
        return;
    }
    
    long long sid = partition(arr, len);

    quicksort(arr, sid);
    quicksort(arr+sid+1, len-sid-1);
}
