#include <iostream>
#include <vector>

using namespace std;
int find_first_occurrence(vector<int> &arr, int target) {
    // target exceeds arr length
    if (target > arr[arr.size() - 1]) {
        return -1;
    }

    // initialise vars
    int min = 0, max = arr.size() - 1, mid;
    int min_valid = -1;

    // target smaller than min or larger than max
    if (target < arr[min] || target > arr[max]) {
        return -1;
    }
    // edge case: size of 1
    if (min == max) {
        if (arr[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }
    // main loop
    while (min < max) {
        mid = min + (max - min) / 2; // update mid after loop
        if (arr[mid] == target) {
            max = mid; // bring the max down to found value (search for more)
            min_valid = mid;
        } else if (arr[mid] > target) {
            max = mid - 1; // check if this ever breaks
        } else {           // arr[mid] > target
            min = mid + 1;
        }
    }

    return min_valid;
}

int main() {
    vector vec = {2, 3, 5, 7, 11};
    cout << find_first_occurrence(vec, 2) << "\n";
    return 0;
}