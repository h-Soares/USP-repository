def binary_search(array, number):
    array = sorted(array)  # increase time of execution, minimum: O(N * logN)
    comparisons = 0
    init = 0
    end = len(array) - 1
    comparisons += 1
    while init <= end:
        comparisons += 1
        middle = int((init + end) / 2)
        comparisons += 1
        if array[middle] == number:
            print(f"Total comparisons for binary search: {comparisons}")
            return middle
        if number < array[middle]:
            end = middle - 1
        else:
            init = middle + 1
        comparisons += 1
    return None
