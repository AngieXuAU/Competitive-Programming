
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> two_sum(std::vector<int> &arr, int target) {
    std::unordered_map<int, int> seen;

    seen[arr[0]] = 0;

    for (int i = 1; i < arr.size(); i++) {
        int tmp = arr[i];
        int tmp_target = target - tmp;
        if (seen.contains(tmp_target)) {
            return {seen.at(tmp_target), i};
        }
        seen[tmp] = i;
    }
    return {-1};
}

void pprint(std::vector<int> result) {
    for (int element : result) {
        std::cout << element << "\t";
    }
}

int main() {
    std::vector<int> arr1 = {3, 3, 2};

    pprint(two_sum(arr1, 5));

    return 0;
}