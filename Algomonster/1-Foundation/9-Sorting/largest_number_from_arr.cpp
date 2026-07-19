#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string largest_number_from_array(std::vector<int> &nums) {
    std::string result = "";

    // edge case: all 0s
    bool all_zeroes = true;
    for (int digit : nums) {
        if (digit != 0) {
            all_zeroes = false;
            break;
        }
    }

    if (all_zeroes) {
        return "0";
    }

    // normal sorting
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return std::to_string(a) > std::to_string(b);
    });

    for (int num : nums) {
        result.append(std::to_string(num));
    }

    return result;
}

int main() {
    // std::vector nums = {3, 30, 34, 5, 9};
    std::vector nums = {121, 12};
    std::string result = largest_number_from_array(nums);
    std::cout << result << std::endl;
}

// Input: [3, 30, 34, 5, 9]
// Output: "9534330"
// Explanation: Arrange numbers to form 9-5-34-3-30.
//              This gives 9534330, which is larger than any other arrangement.

// Input: [10, 2]
// Output: "210"
// Explanation: "210" is larger than "102".

// Input: [0, 0, 0]
// Output: "0"
// Explanation: When all numbers are zero, return "0" instead of "000".

// Input: [121, 12]
// Output: "12121"
// Explanation: "12121" is larger than "12112".
//              Comparing: "121" + "12" = "12112" vs "12" + "121" = "12121"