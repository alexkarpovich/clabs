#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define min(a, b) (((a) < (b)) ? (a) : (b)) 
#define min(a, b) (((a) > (b)) ? (a) : (b)) 

int process(int k, int s_count, int* s) {
  int count, max_len = 0;
  int* rmd = (int*)calloc(k, sizeof(int));

  for (int i = 0; i < s_count; i++) {
    ++rmd[s[i] % k];
  }

  count = min(rmd[0], 1);
  for (int i = 1; i < k / 2 + 1; i++) {
      if (i != k - i) {
          count += max(rmd[i], rmd[k - i]);
      }
  }

  if (k % 2 == 0) ++count;

  return count;
}

int main(void) {
    int errnum = 0;
    int len, max_subset = 0, id = 0, prev_i = 0;
    int* data = malloc(3 * sizeof(int));

    char *buffer = NULL, *tmp = malloc(10 * sizeof(char));
    size_t size = 0;

    /* Open your_file in read-only mode */
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        errnum = errno;
        goto exit;
    }

    /* Get the buffer size */
    fseek(fp, 0, SEEK_END); /* Go to end of file */
    size = ftell(fp); /* How many bytes did we pass ? */

    /* Set position of stream to the beginning */
    rewind(fp);

    /* Allocate the buffer (no need to initialize it with calloc) */
    buffer = malloc(size * sizeof(*buffer)); /* size + 1 byte for the \0 */

    /* Read the file into the buffer */
    fread(buffer, size, 1, fp); /* Read 1 chunk of size bytes from fp into buffer */

    for (int i = 0; i < size; i++) {
        switch (buffer[i]) {
            case '\n':
                data = (int*) realloc(data, data[0] * sizeof(int));
            case ' ':
                len = i - prev_i;
                strncpy(tmp, buffer + prev_i, len);
                tmp[len] = '\0';
                data[id++] = atoi(tmp);
                prev_i = i + 1;
        }
    }

    max_subset = process(data[1], data[0], data + 3);

    printf("Max non-divisible subset length = %d (expected = %d)\n", max_subset, data[2]);
    
    exit:
        printf("%s\n", strerror(errnum));

        return errnum;
}