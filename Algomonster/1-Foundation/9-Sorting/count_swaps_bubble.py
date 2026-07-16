def count_swaps_bubble_sort(arr: list[int]) -> int:
    swaps_count = 0

    for j in range(0, -len(arr), -1):
        old_swaps_count = swaps_count

        for i in range(len(arr) - 1):
            if arr[i+1] < arr[i]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                swaps_count += 1
        
        if swaps_count == old_swaps_count:
            break

    print(arr)
    return swaps_count

print(count_swaps_bubble_sort([1, 2, 3, 4, 5]))     # 0
print(count_swaps_bubble_sort([5, 4, 3, 2, 1]))     # 10
print(count_swaps_bubble_sort([3, 1, 4, 2]))        # 3

