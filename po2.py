#!/usr/bin/python3

from multiprocessing import Process
from multiprocessing import Pool
from math import floor
import time
import random

def fun():

    print('starting fun')
    time.sleep(2)
    print('finishing fun')

#def qsort_sub(arr=[]):
#    arr.sort()


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

def main():

    p = Process(target=fun)
    p.start()
    p.join()


if __name__ == '__main__':

    #print('starting main')
    #main()
    #print('finishing main')
    NN = 100000
    N = 2000
    K = 10
    arr = random.sample(range(1, NN), N)
    print('Before sort')
    print(arr)
    with Pool(4) as p:
        #p.map(list.sort, partition(arr, 4))
        results = p.map(sort_sub, partition(arr, N//K))
    print('After sort')
    #print(results)
    outputs = [result[0 : K] for result in results]
    #print(outputs)
    outputs2 = []
    for i in range(len(outputs)):
        outputs2.extend(outputs[i])
    #print(outputs2)
    outputs2.sort(reverse=True)
    print(outputs2[K])
    print('Expert')
    arr.sort(reverse=True)
    #print(arr)
    print(arr[K])

