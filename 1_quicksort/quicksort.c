#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

int partition(int* arr, int lid, int rid) {

}

void quicksort_helper(int* arr, int lid, int rid) {
    if (lid >= rid) {
        return 
    }
    
    int sid = partition(arr, lid, rid);

    quicksort_helper(arr, lid, sid);
    quicksort_helper(arr, sid + 1, rid);
}

void quicksort(int* arr) {
    int len = ARRAY_SIZE(arr)
    quicksort_helper(arr, 0, len - 1)
}
