#include <iostream>
#include <vector>

int first_not_smaller(std::vector<int> &arr, int target) {
    if (target > arr[arr.size() - 1]) {
        return -1;
    }

    int min = 0, max = arr.size() - 1;
    int mid = min + (max - min) / 2;

    while (min < max) {

        if (arr[mid] >= target) {
            max = mid;
        } else {
            min = mid + 1;
        }
        mid = min + (max - min) / 2;
    }
    return mid;
}

int main() {
    std::vector vec = {2, 3, 5, 7, 11, 13, 17, 19};
    std::cout << first_not_smaller(vec, 6) << "\n";
    return 0;
}

// Given an array of integers sorted in increasing order and a target, find the
// index of the first element in the array that is larger than or equal to the
// target. Assume that it is guaranteed to find a satisfying number.

// note: assume that it is guaranteed to find a satisfying number: one of the
// test cases includes checking for a target outside the range of the array, so
// i put in the -1 return at the top just in case