#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> minimum_difference_pairs(std::vector<int> &arr) {
    // edge case: smaller than 2
    if (arr.size() < 2) {
        return {};
    }
    // sort the array
    std::sort(arr.begin(), arr.end());

    std::vector<std::vector<int>> result;

    // initial value for difference and result
    int min_diff = abs(arr[1] - arr[0]);
    result.push_back({arr[0], arr[1]});

    for (int i = 2; i < arr.size(); i++) {
        int diff = abs(arr[i] - arr[i - 1]);
        if (diff < min_diff) { // less than min_diff: clear and add new pair
            result.clear();
            result.push_back({arr[i - 1], arr[i]});
            min_diff = diff;
        } else if (diff == min_diff) { // equal: add new pair
            result.push_back({arr[i - 1], arr[i]});
        } else { // otherwise do nothing
            continue;
        }
    }
    return result;
}

void pprint(std::vector<int> result) {
    for (int i = 0; i < result.size() - 1; i++) {
        std::cout << result[i] << ", ";
    }
    std::cout << result[result.size() - 1] << std::endl;
}

int main() {
    std::vector nums = {4, 2, 1, 3};

    for (std::vector<int> vec : minimum_difference_pairs(nums)) {
        pprint(vec);
    }
}