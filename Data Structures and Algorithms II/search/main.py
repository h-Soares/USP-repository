import timeit

from search.BinarySearch import binary_search
from search.LinearSearch import linear_search


def linear_search_wrapper():
    linear_search(numbs, 100000000)


def binary_search_wrapper():
    binary_search(numbs, 100000000)


if __name__ == "__main__":
    numbs = [i for i in range(1, 100000001)]

    linear_time = timeit.timeit("linear_search_wrapper()", setup="from __main__ import linear_search_wrapper", number=1)
    print(f"Total time for linear search: {linear_time} seconds")

    binary_time = timeit.timeit("binary_search_wrapper()", setup="from __main__ import binary_search_wrapper", number=1)
    print(f"Total time for binary search: {binary_time} seconds")
