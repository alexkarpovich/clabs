#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c) {

    int diff, i = 0, prev_thunderheads = 0, j_count = 0;

    while (i < c_count) {
        if (c[i] == 1 || i == c_count - 1) {
            diff = i + (i != c_count - 1) - prev_thunderheads + 1;
            j_count += diff / 2;
            prev_thunderheads = i + 1;
            ++i;
        } else ++i;
    }

    return j_count;

}

int main(void) {

    int c[6] = {0, 0, 0, 1, 0, 0}; 
    int j_count = jumpingOnClouds(6, c);

    printf("%d\n", j_count);

    return 0;

}