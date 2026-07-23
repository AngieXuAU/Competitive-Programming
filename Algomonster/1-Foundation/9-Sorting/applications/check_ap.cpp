#include <algorithm>
#include <iostream>
#include <vector>

bool can_make_arithmetic_progression(std::vector<int> &arr) {

    // edge case: 2 or fewer elements
    if (arr.size() <= 2) {
        return true;
    }

    // sort
    std::sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; i++) {
        if ((arr[i + 1] - arr[i]) != diff) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector nums = {1, 2, 4};
    std::cout << can_make_arithmetic_progression(nums) << std::endl;
}