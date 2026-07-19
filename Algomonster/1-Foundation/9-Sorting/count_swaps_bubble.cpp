#include <algorithm>
#include <iostream>
#include <vector>

int count_swaps_bubble_sort(std::vector<int> &arr) {
    int n = arr.size();
    int swap_count = 0;

    // sorted = first sorted ind
    for (int sorted = n; sorted > 0; sorted--) {
        bool swapped = false;
        for (int index = 0; index < n - 1; index++) {
            if (arr[index] > arr[index + 1]) {
                std::swap(arr[index], arr[index + 1]);
                swap_count++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
    return swap_count;
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    int count = count_swaps_bubble_sort(numbers);

    for (int num : numbers) {
        std::cout << num << " ";
    }
    // Output: 11 12 22 25 34 64 90

    std::cout << "\nFinal Count: " << count << std::endl;
    return 0;
}