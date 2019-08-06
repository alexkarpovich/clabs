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

void extend(int* max_subset, int k, array* compsub, array* candidates, array* not) {
    int v;

    while (candidates->len > 0 && check_not(k, candidates, not)) {
        v = candidates->d[0];
        append(compsub, v);

        array* new_candidates = init(CAP_SIZE), *new_not = init(CAP_SIZE);
        new_sets(k, v, candidates, not, new_candidates, new_not);

        if (!new_candidates->len && !new_not->len) {
            if (compsub->len > *max_subset) *max_subset = compsub->len;
        } else extend(max_subset, k, compsub, new_candidates, new_not);

        del(candidates, v);
        del(compsub, v);
        append(not, v);
    }
}



int main(void) {
    int max_subset = 0, id = 0, prev_i = 0;
    int* data = malloc(3 * sizeof(int));

    char *buffer = NULL, *tmp = malloc(10 * sizeof(char));
    size_t size = 0;

    /* Open your_file in read-only mode */
    FILE *fp = fopen("textcase.txt", "r");

    /* Get the buffer size */
    fseek(fp, 0, SEEK_END); /* Go to end of file */
    size = ftell(fp); /* How many bytes did we pass ? */

    /* Set position of stream to the beginning */
    rewind(fp);

    /* Allocate the buffer (no need to initialize it with calloc) */
    buffer = malloc((size + 1) * sizeof(*buffer)); /* size + 1 byte for the \0 */

    /* Read the file into the buffer */
    fread(buffer, size, 1, fp); /* Read 1 chunk of size bytes from fp into buffer */

    /* NULL-terminate the buffer */
    buffer[size] = '\0';

    for (int i = 0; i < size; i++) {
        if (buffer[i] == ' ') {
            strncpy(tmp, buffer + prev_i, i - prev_i);
            data[id++] = atoi(tmp);
            prev_i = i + 1;
        } else if (buffer[i] == '\n') {
            data = (int*) realloc(data, data[0] * sizeof(int));
        }  
    }

    array* candidates = init(data[0] + CAP_SIZE), *not = init(CAP_SIZE), *compsub = init(CAP_SIZE);

    memcpy(candidates->d, data + 3, data[0] * sizeof(int));
    candidates->len = data[0];

    extend(&max_subset, data[1], compsub, candidates, not);

    printf("Max non-divisible subset length = %d (expected = %d)\n", max_subset, data[2]);
    return 0;
}