#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>

std::vector<int> intersection_of_arrays(const std::vector<int> &nums1,
                                        const std::vector<int> &nums2) {
    // create a hash map for the first vector
    int i = 0, j = 0;
    std::vector<int> intersection;

    while (i < nums1.size() && j < nums2.size()) {

        if (nums1[i] == nums2[j]) {
            intersection.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] > nums2[j]) {
            j++; // move the pointer forward until x <= y
        } else { // ie. x < y
            i++;
        }
    }

    return intersection;
}

void pprint(const std::vector<int> &result) {
    for (int element : result) {
        std::cout << element;
    }
}

int main() {
    std::vector<int> arr1 = {2, 2};
    std::vector<int> arr2 = {1, 1, 2, 2};
    std::vector<int> arr3 = {4, 5, 9};
    std::vector<int> arr4 = {4, 4, 8, 9, 9};
    std::vector<int> arr5 = {1, 2, 3};
    std::vector<int> arr6 = {4, 5, 6};

    pprint(intersection_of_arrays(arr1, arr2));
    pprint(intersection_of_arrays(arr3, arr4));
    pprint(intersection_of_arrays(arr5, arr6));

    return 0;
}