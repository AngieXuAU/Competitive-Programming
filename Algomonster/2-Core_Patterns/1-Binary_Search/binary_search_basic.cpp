// Given a sorted array of integers and an integer called target, find the
// element that equals the target and return its index. If the element is not
// found, return -1.
#include <iostream>
#include <vector>

int binary_search(std::vector<int> &arr, int target) {
    int max = arr.size() - 1;
    int i = max / 2;
    std::vector<int> bounds = {0, max};

    while (true) {
        if (arr[i] == target) {
            return i;
        } else if ((bounds[1] - bounds[0]) == 1) { // adjacent bounds
            break;
        } else if (arr[i] < target) {
            bounds[0] = i;
            i = (i + bounds[1]) / 2;
        } else {           // target < val @ i
            bounds[1] = i; // set upper bound to be i
            i = (i + bounds[0]) / 2;
        }
    }
    return -1;
}

void run_test(const std::string &name, std::vector<int> arr, int target,
              int expected) {
    int result = binary_search(arr, target);
    std::cout << "[Test: " << name << "] ";
    if (result == expected) {
        std::cout << "SUCCESS (Found index: " << result << ")\n";
    } else {
        std::cout << "FAILED (Expected: " << expected << ", Got: " << result
                  << ")\n";
    }
}

int main() {
    // 1. Standard cases
    run_test("Standard Odd Size (Element present)", {1, 3, 5, 7, 9}, 5, 2);
    run_test("Standard Even Size (Element present)", {1, 3, 5, 7, 9, 11}, 7, 3);
    run_test("Element not present", {1, 3, 5, 7, 9}, 4, -1);

    // 2. Boundary cases
    run_test("Target is the first element", {1, 3, 5, 7, 9}, 1, 0);
    run_test("Target is the last element", {1, 3, 5, 7, 9}, 9, 4);

    // 3. Extreme edge cases
    run_test("Single element (Present)", {5}, 5, 0);
    // WARNING: Test below might run forever or crash based on implementation
    run_test("Single element (Not present)", {5}, 3, -1);

    // WARNING: Test below might crash based on implementation
    run_test("Empty array", {}, 5, -1);

    return 0;
}
