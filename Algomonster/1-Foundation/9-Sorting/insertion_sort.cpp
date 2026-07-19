#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> &arr) {
    int n = arr.size();

    for (int last_sorted = 0; last_sorted < n - 1; last_sorted++) {
        // key = next unsorted val to compare
        // target index = where that val should go
        int key = arr[last_sorted + 1], target_index = 0;

        // TODO: optimise this double loop
        // find target index, [0, last_sorted+1] (increment after check)
        while (key > arr[target_index] && target_index <= last_sorted) {
            target_index++;
        }

        // if already in the correct spot
        if (target_index == last_sorted + 1) {
            continue;
        }

        for (int j = last_sorted; j >= target_index; j--) {
            arr[j + 1] = arr[j];
        }
        arr[target_index] = key;
    }
    return arr;
}

int main() {
    std::vector<int> numbers = {12, 11, 13, 5, 6};
    insertionSort(numbers);

    for (int num : numbers) {
        std::cout << num << " ";
    }
    // Output: 5 6 11 12 13

    return 0;
}