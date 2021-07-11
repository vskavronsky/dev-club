def find_smallest(arr):
    smallest = arr[0]
    smallest_index = 0

    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index


def selection_sort(arr):
    sorted_arr = []

    for i in range(len(arr)):
        smallest_index = find_smallest(arr)
        sorted_arr.append(arr.pop(smallest_index))
    return sorted_arr


if __name__ == '__main__':
    print(selection_sort([5, 3, 6, 2, 10]))
    print(selection_sort([7, 2, 6, 1, 2]))
