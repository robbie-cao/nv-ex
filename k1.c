#include <stdio.h>
#include <stdlib.h>

#define N   50
#define K   5

// 题设:
// - N个无序元素的数组
// - 求第K(1 <= K <= N)大的元素
//
// 思路:
//
// 复杂度分析:
// - 空间复杂度: O()
// - 时间复杂度: O()

int compare_asc(const void *pe1, const void *pe2)
{
    int v1 = *(int *)pe1;
    int v2 = *(int *)pe2;
    return (v1 < v2) ? -1 : (v1 > v2) ? 1 : 0;
}

int compare_desc(const void *pe1, const void *pe2)
{
    int v1 = *(int *)pe1;
    int v2 = *(int *)pe2;
    return (v1 > v2) ? -1 : (v1 < v2) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    int i;
    int num[] = {36, 14, 32, 28, 7, 25, 96, 0, 89, 69, 21, 85, 70, 58, 4, 38, 16, 29, 44, 88, 15, 31, 49, 23, 64, 42, 30, 76, 63, 72, 39, 43, 50, 33, 48, 12, 82, 75, 1, 22, 10, 34, 84, 68, 83, 11, 5, 71, 97, 3};
    int num2[] = {36, 14, 32, 28, 7, 25, 96, 0, 89, 69, 21, 85, 70, 58, 4, 38, 16, 29, 44, 88, 15, 31, 49, 23, 64, 42, 30, 76, 63, 72, 39, 43, 50, 33, 48, 12, 82, 75, 1, 22, 10, 34, 84, 68, 83, 11, 5, 71, 97, 3};


    int size = sizeof(num) / sizeof(num[0]);
    qsort(num, size, sizeof(num[0]), compare_asc);
    qsort(num2, size, sizeof(num2[0]), compare_desc);

    printf("Array in ascending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d  ", num[i]);
    }
    printf("\n");
    printf("Array in descending order:\n");
    for (i = 0; i < size; i++) {
        printf("%d  ", num2[i]);
    }
    printf("\n");

    return 0;
}

