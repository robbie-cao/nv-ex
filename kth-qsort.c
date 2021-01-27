#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N   50
#define K   7


/*
// 题设:
// - N个无序元素的数组
// - 求第K(1 <= K <= N)大的元素
//
// 思路:
// 分治归并
// 1) 将数组分成K组，N % K !=0 则(K + 1)组
//    对K(or K+1)组分别进行快速排序
// 2) 对排序后K(or K+1)组结果取前K个元素组成一个新的数组
//    对新数组进行快速排序或归并排序，新书组排序后第K个元素即为所求结果
// 证明:
// 考虑K个M(M >= K)元素的集合S1(a1, a2, ..., am), S2(b1, b2, ..., bm), ..., Sk(k1, k2, ..., km)
// S = S1 U S2 U ... U Sk
// 对这些集合分别降序排序得到S1'(a1', a2', ..., am'), S2'(b1', b2', ..., bm'), ..., Sk'(k1', k2', ..., km')
// S' = S1''(a1', a2', ..., ak') U S2''(b1', b2', ..., bk') U ... U Sk''(k1', k2', ..., kk')
// 则S中最大K个数一定包含在S'中
//
// 复杂度分析:
// - 空间复杂度: O(N*log(N/K) + 2*(K^2)*log(K))
// - 时间复杂度: O(N + K^2)
//
// 改进:
// 步骤1)分组快速排序可以并行处理(eg, fork-join model)
*/

int compare_desc(const void *pe1, const void *pe2)
{
    int v1 = *(int *)pe1;
    int v2 = *(int *)pe2;
    return (v1 > v2) ? -1 : (v1 < v2) ? 1 : 0;
}


// Find the K-th max number in array
// param:
// - array: array of number in random order
// - size: size of array
// - k: the K-th max
// return:
// -1 for error, or the expected result
int find_k_th_max(int array[], unsigned int size, unsigned int kth)
{
    int res = 0;
    int *array_sorted = NULL;
    int i, j;

    if (!array || !size || !kth || kth >= size) {
        return -1;
    }

    int sub_arr_size = size / kth;
    int remained = size % kth;
    int n_k = size - remained;

    for (i = 0; i < n_k; i += sub_arr_size) {
        qsort(array + i, sub_arr_size, sizeof(array[0]), compare_desc);
    }
    if (remained) {
        qsort(array + n_k, remained, sizeof(array[0]), compare_desc);
    }

    int res_arr_size = kth * (kth + !!remained);
    int *res_array = (int *)malloc(res_arr_size * sizeof(array[0]));
    if (!res_array) {
        printf("malloc error\n");
        return -1;
    }
    for (i = 0; i < res_arr_size; i++) {
        res_array[i] = INT_MIN;
    }

    int grp_idx = 0;
    for (i = 0; i < n_k; i += sub_arr_size) {
        for (j = 0; j < kth; j++) {
            res_array[grp_idx * kth + j] = array[i + j];
        }
        grp_idx += 1;
    }
    int res_arr_idx = grp_idx * kth;
    if (remained) {
        for (j = 0; j < kth && j < remained; j++) {
            res_array[res_arr_idx + j] = array[size - remained + j];
        }
    }

    qsort(res_array, res_arr_size, sizeof(array[0]), compare_desc);
    res = res_array[kth - 1];

    free(res_array);

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
    printf("N: %d, K: %d\n", N, K);

    int res = find_k_th_max(num, N, K);

    printf("The K-th max num: %d\n", res);

    return 0;
}

