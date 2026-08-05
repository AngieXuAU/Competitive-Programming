#include <iostream>
#include <vector>

using namespace std;

int find_min_rotated(std::vector<int> &arr) {
    // if only one value
    if (arr.size() == 1) {
        return 0;
    }

    // initialise bounds
    int min = 0, max = arr.size() - 1, mid = min + (max - min) / 2, val,
        last = arr[arr.size() - 1];

    while (min < max) {
        val = arr[mid];

        if (val > last) {
            min = mid + 1;
        } else { // val <= last
            max = mid;
        }
        mid = min + (max - min) / 2;
    }

    return mid;
}

int main() {
    vector vec = {1, 2, 3, 4, 5};
    cout << find_min_rotated(vec) << "\n";
    return 0;
}
