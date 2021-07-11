import heartrate
import snoop
# heartrate.trace(browser=True)


@snoop
def quick_sort(arr):
    # low = 0
    # high = len(arr) - 1

    if len(arr) < 2:
        return arr
    else:
        # pivot_index = (low + high) // 2
        # pivot = arr[(0 + (len(arr) - 1)) // 2]
        pivot = arr[0]
        less = [i for i in arr[1:] if i <= pivot]
        greater = [i for i in arr[1:] if i > pivot]
        return quick_sort(less) + [pivot] + quick_sort(greater)


if __name__ == '__main__':
    print(quick_sort([2, 6, 4, 8, 1]))
