#include <iostream>
// #include <string>
#include <unordered_map>
#include <vector>
// #include <algorithm>

std::vector<int> intersection_of_arrays(const std::vector<int> &nums1,
                                        const std::vector<int> &nums2) {
    // create a hash map for the first vector
    std::unordered_map<int, int> record;
    for (int x : nums1) {
        record[x]++;
    }

    // iterate through 2nd vector
    std::vector<int> intersection;
    for (int y : nums2) {
        if (record[y] > 0) {
            record[y]--;
            intersection.push_back(y);
        }
    }

    return intersection;
}

void pprint(std::vector<int> result) {
    for (int element : result) {
        std::cout << element;
    }
}

int main() {
    std::vector<int> arr1 = {2, 2};
    std::vector<int> arr2 = {1, 2, 2, 1};
    std::vector<int> arr3 = {4, 9, 5};
    std::vector<int> arr4 = {9, 4, 9, 8, 4};
    std::vector<int> arr5 = {1, 2, 3};
    std::vector<int> arr6 = {4, 5, 6};

    pprint(intersection_of_arrays(arr1, arr2));
    pprint(intersection_of_arrays(arr3, arr4));
    pprint(intersection_of_arrays(arr5, arr6));

    return 0;
}