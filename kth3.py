#!/usr/bin/python3

from multiprocessing import Process
from multiprocessing import Pool
from math import floor
import time
import random
import sys

def info(x):
    #print(x)
    pass

# Find the K-th max number in an array
# 为简单起见，设定K远小于N(K << N)且N为K的整数倍(N % K == 0)

def partition(ls, size):

    """
    Returns a new list with elements
    of which is a list of certain size.

    >>> partition([1, 2, 3, 4], 3)
    [[1, 2, 3], [4]]
    """
    return [ls[i : (i+size)] for i in range(0, len(ls), size)]

def sort_sub(arr):

    arr.sort(reverse=True)
    return arr

if __name__ == '__main__':

    NN = sys.maxsize
    NN = 2 ** 30
    N = 4096 * 1024 * 8
    K = 16
    arr = random.sample(range(1, NN), N)
    info('Array:')
    info(arr)
    print('Find the K-th max number - N: %d, K: %d' % (N, K))

    # Algorith 1) - 分组排序(多核并行)
    # 把数组分成K组，每组包含N/K个元素，把子数组分发给Pool.map并行处理
    start_time = time.clock()
    with Pool(4) as p:
        results = p.map(sort_sub, partition(arr, N//K))

    # 合并分组排序结果
    outputs = [result[0 : K] for result in results]
    outputs2 = []
    for i in range(len(outputs)):
        outputs2.extend(outputs[i])
    # 对合并分组排序，排序后数组第K项即为结果
    outputs2.sort(reverse=True)
    end_time = time.clock()
    print('Result:')
    print(outputs2[K])
    print('Time cost: %f' % (end_time - start_time))

    # Algorith 2) - 分组排序(单核串行)
    start_time = time.clock()
    res_a = []
    arr_p = partition(arr, N//K)
    info(arr_p)
    for i in range(K):
        arr_p[i].sort(reverse=True)
        info(arr_p[i])
        res_a.extend(arr_p[i][0 : K])
    info(res_a)
    res_a.sort(reverse=True)
    info(res_a)
    end_time = time.clock()
    print('Result:')
    print(res_a[K])
    print('Time cost: %f' % (end_time - start_time))

    # Algorith 3) - 整体排序
    start_time = time.clock()
    arr.sort(reverse=True)
    end_time = time.clock()
    print('Verify:')
    print(arr[K])
    print('Time cost: %f' % (end_time - start_time))

