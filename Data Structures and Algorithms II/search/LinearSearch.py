def linear_search(array, number):
    comparisons = 0
    for i in range(len(array)):
        comparisons += 1
        if array[i] == number:
            print(f"Total comparisons for linear search: {comparisons}")
            return i
    return None
