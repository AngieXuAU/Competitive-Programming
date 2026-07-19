#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> &arr) {
    int n = arr.size();

    // sorted = first sorted ind
    for (int sorted = n; sorted > 0; sorted--) {
        for (int index = 0; index < n - 1; index++) {
            if (arr[index] > arr[index + 1]) {
                std::swap(arr[index], arr[index + 1]);
            }
        }
    }
    return arr;
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(numbers);

    for (int num : numbers) {
        std::cout << num << " ";
    }
    // Output: 11 12 22 25 34 64 90

    return 0;
}