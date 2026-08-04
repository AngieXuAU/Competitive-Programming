#include <iostream>
#include <vector>

using namespace std;

int find_boundary(std::vector<bool> &arr) {
    // edge case: all true
    if (arr[0] == true) {
        return 0;
    }

    // edge case: all false
    if (arr[arr.size() - 1] == false) {
        return -1;
    }

    // initialise min and max
    int min = 0, max = arr.size() - 1, i = min + (max - min) / 2;
    while (min <= max) {
        if (arr[i] == true && arr[i - 1] == false) { // found target
            return i;
        } else if (arr[i] == true) {
            max = i - 1;
            i = min + (max - min) / 2; // overshot
        } else {                       // ie. arr[i] == false
            min = i + 1;
            i = min + (max - min) / 2; // undershot
        }
    }
    return -1;
}

int main() {
    vector vec = {false, false, true, true, true};

    cout << find_boundary(vec) << "\n";
}