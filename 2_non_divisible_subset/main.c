#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP_SIZE 10


typedef struct {
    int len;
    int cap;
    int* d;
} array;

int max(int x, int y) { 
    return x ^ ((x ^ y) & -(x < y));  
} 

void printa(array* arr) {
    for (int i = 0; i < arr->len; i++) printf("%d ", arr->d[i]);
    printf("\n");
}

array* init(int cap) {
    array* arr = (int*)malloc(sizeof(array));
    arr->len = 0;
    arr->cap = cap;
    arr->d = (int*)malloc(arr->cap * sizeof(int));

    return arr;
}

void append(array* arr, int v) {
    if (arr->len == arr->cap) {
        arr->cap = arr->cap + CAP_SIZE;
        arr->d = (int*)realloc(arr->d, arr->cap * sizeof(int));
    }

    arr->d[arr->len++] = v;
}

void del(array* arr, int v) {
    if (arr->d[arr->len - 1] == v) --arr->len;
    else {
        for (int i = 0; i < arr->len; i++) {
            if (arr->d[i] == v) {
                memcpy(arr->d + i, arr->d + i + 1, (arr->len - i) * sizeof(int));
                --arr->len;
            }
        }
    }
}

int check_not(int k, array* candidates, array* not) {
    int counter;

    for (int i = 0; i < not->len; i++) {
        counter = 0;

        for (int j = 0; j < candidates->len; j++) {
            if ((not->d[i] + candidates->d[j]) % k != 0) ++counter;
        }

        if (counter == candidates->len) return 0;
    }

    return 1;
}

void new_sets(int k, int v, array* candidates, array* not, array* new_candidates, array* new_not) {
    int max_len = max(candidates->len, not->len);

    for (int i = 0; i < max_len; i++) {
        if (i < candidates->len && v != candidates->d[i] && (v + candidates->d[i]) % k != 0) {
            append(new_candidates, candidates->d[i]);   
        }

        if (i < not->len && v != not->d[i] && (v + not->d[i]) % k != 0) {
            append(new_not, not->d[i]);   
        }
    }
}

void extend(int k, array* compsub, array* candidates, array* not) {
    int v;
    array* new_candidates = init(CAP_SIZE), *new_not = init(CAP_SIZE);

    while (candidates->len > 0 && check_not(k, candidates, not)) {
        v = candidates->d[0];
        append(compsub, v);
        new_sets(k, v, candidates, not, new_candidates, new_not);

        if (!new_candidates->len && !new_not->len) {
            printf("Max clique = %d:\n", compsub->len);
            printa(compsub);
        } else extend(k, compsub, new_candidates, new_not);

        del(candidates, v);
        del(compsub, v);
        append(not, v);
    }
}

int main(void) {
    int k = 7;
    int A[15] = {278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436};
    array* candidates = init(15 + CAP_SIZE), *not = init(CAP_SIZE), *compsub = init(CAP_SIZE);

    memcpy(candidates->d, A, 15 * sizeof(int));
    candidates->len = 15;

    extend(k, compsub, candidates, not);

    printf("Hello World\n");
    return 0;
}