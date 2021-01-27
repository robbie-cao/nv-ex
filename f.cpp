#include <stdio.h>
#include <stdlib.h>

#define N   50
#define K   5

int find_k_th_max(int array[], unsigned int size, unsigned int kth)
{
    int res = 0;
    int *array_sorted = NULL;
    int i, j = 0;

    array_sorted = (int* )calloc(size, sizeof(int));
    if (!array_sorted) {
        exit(0);
    }

    for (i = 0; i < size; i++) {
        array_sorted[array[i]] = array[i];
    }

    for (i = size * 2 - 1; i >= 0; i--) {
        if (array_sorted[i]) {
            j += 1;
            if (j >= kth) {
                res = array_sorted[i];
                break;
            }
        }
    }

    free(array_sorted);

    return res;
}

int main(int argc, char *argv[])
{
    int i;
    int num[] = {36, 14, 32, 28, 7, 25, 96, 0, 89, 69, 21, 85, 70, 58, 4, 38, 16, 29, 44, 88, 15, 31, 49, 23, 64, 42, 30, 76, 63, 72, 39, 43, 50, 33, 48, 12, 82, 75, 1, 22, 10, 34, 84, 68, 83, 11, 5, 71, 97, 3};


    int size = sizeof(num) / sizeof(num[0]);

    printf("Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d  ", num[i]);
    }
    printf("\n");

    int res = find_k_th_max(num, N, K);

    printf("The K-th max num: %d\n", res);

    return 0;
}

