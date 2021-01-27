#include <stdio.h>
#include <stdlib.h>

#define N   50
#define K   5

// 题设:
// - N个元素的数组
// - 数组元素取值范围(0...2*N-1)
// - 数组元素值唯一（没有重复）
// - 数组乱序:w
// - 求第K(1 <= K <= N)大的元素
//
// 思路:
// 构建一个2*N数组b，遍历数组a, 将数组a元素内容值存放数组b实现排序，
// 即b[a[i]] = a[i]
// 排序后的数组b会有N个空位
// 遍历数组b，找到第K个非0值即为结果
//
// 复杂度分析:
// - 空间复杂度: O(N)
// - 时间复杂度: O(N)

// Find the K-th max number in array
// param:
// - array: array of number in (0, 2*size-1)
// - size: size of array
// - k: the K-th max
// return:
// -1 for error, or the expected result
//
int find_k_th_max(int array[], unsigned int size, unsigned int kth)
{
    int res = 0;
    int *array_sorted = NULL;
    int i, j = 0;

    if (!array || !size || kth >= size) {
        return -1;
    }

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

