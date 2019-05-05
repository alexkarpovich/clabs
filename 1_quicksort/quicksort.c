
int partition(int* arr, int lid, int rid) {
    int pivot = arr[(rid - lid) >> 1];    
    int lidc = lid;
    int ridc = rid;

    while (1) {
        while (lidc < rid && arr[lidc] < pivot) ++lidc;
        while (ridc > lid && arr[ridc] >= pivot) --ridc;

        if (lidc >= ridc) {
            return lidc;
        }

        int tmp = arr[lidc];
        arr[lidc] = arr[ridc];
        arr[ridc] = tmp;        
    }
}

void quicksort_helper(int* arr, int lid, int rid) {
    if (lid >= rid) {
        return;
    }
    
    int sid = partition(arr, lid, rid);

    if (lid < sid - 1) {
        quicksort_helper(arr, lid, sid - 1);
    }

    if (rid > sid + 1) {
        quicksort_helper(arr, sid + 1, rid);
    }
}

void quicksort(int* arr, int len) {
    quicksort_helper(arr, 0, len - 1);
}
