from multiprocessing import Pool
import random


from math import floor

def partition(ls, size):
    """
    Returns a new list with elements
    of which is a list of certain size.

        >>> partition([1, 2, 3, 4], 3)
        [[1, 2, 3], [4]]
    """
    return [ls[i:i+size] for i in range(0, len(ls), size)]

def f(x):
    return x*x

def sort_sub(arr):
    print(arr)
    arr.sort()
    print(arr)
    return arr

if __name__ == '__main__':
    with Pool(5) as p:
        print(p.map(f, [1, 2, 3]))

    ls = [1, 2, 3, 4, 5]
    n = 3
    res = partition(ls, floor(len(ls)/n))
    print(res)
    #assert res == [[1, 2], [3, 4], [5]]

    N = 20
    K = 2
    arr = random.sample(range(1, 100), N)
    print('Before sort')
    print(arr)
    res_a = []
    arr_p = partition(arr, N//K)
    for i in range(K):
        #arr[i*(N/K) : (i+1)*(N/K)].sort()
        #r = arr[i*(N/K) : (i+1)*(N/K)]
        #r.sort()
        arr_p[i].sort()
        res_a.append(arr_p[i])
    print('After sort')
    print(res_a)
    print('Expert')
    arr.sort()
    print(arr)

