#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


// --conta--
int count_below_threshold(double array[], int n, double threshold) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] < threshold) {
      count++;
    }
  }
  return count;
}
// --conta--

void read_file_to_array(double **array, int *n, char filename[]) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        fprintf(stderr, "Could not read file %s\n", filename);
        exit(1);
    }

    fscanf(f, "%d\n", n);
    *array = malloc(*n * sizeof(**array));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%lf\n", &(*array)[i]);
    }
    fclose(f);
}

static uint64_t now_ns(void) {
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        perror("clock_gettime");
        return 0;
    }

    return (uint64_t)ts.tv_sec * 1000000000ULL +
           (uint64_t)ts.tv_nsec;
}


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <0 or 1>\n", argv[0]);
        exit(1);
    }

    char filenames[2][100] = {
        "array0.dat",
        "array1.dat",
    };

    int mode = atoi(argv[1]);

    if (mode < 0 || mode > 1) {
        fprintf(stderr, "Mode should be 0 or 1\n");
        exit(1);
    }

    double *array = NULL;
    int n;
    read_file_to_array(&array, &n, filenames[mode]);

    uint64_t start = now_ns();
    int n_below_threshold = count_below_threshold(array, n, 0.3);
    uint64_t end = now_ns();

    uint64_t elapsed_ns = end - start;

    printf("Input file:                   %s\n", filenames[mode]);
    printf("Array length:                 %d\n", n);
    printf("Below threshold:              %d\n", n_below_threshold);
    printf("Time (count_below_threshold): %lu ns\n", elapsed_ns);
    free(array);

    return 0;
}
