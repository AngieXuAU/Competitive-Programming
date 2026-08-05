#include <iostream>
#include <vector>

using namespace std;

int peak_of_mountain_array(std::vector<int> &arr) {
    int min = 1, max = arr.size() - 2, mid = min + (max - min) / 2;
    int val, before, after;

    while (min < max) {
        val = arr[mid], before = arr[mid - 1], after = arr[mid + 1];

        if (val > before && val > after) { // found
            return mid;
        } else if (before < val && val < after) {
            min = mid + 1;
        } else if (before > val && val > after) {
            max = mid - 1;
        }

        mid = min + (max - min) / 2;
    }
    return mid;
}

int main() {
    vector vec = {3, 9, 8, 6, 4};
    cout << peak_of_mountain_array(vec) << "\n";
    return 0;
}