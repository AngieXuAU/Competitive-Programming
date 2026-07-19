#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string largest_number_from_array(std::vector<std::string> &nums) {
    std::string result = "";

    std::sort(nums.begin(), nums.end());

    for (std::string str : nums) {
        result.append(str);
    }
    return result;
}

int main() {
    std::vector<std::string> nums = {"3", "30", "34", "5", "9"};
    std::string result = largest_number_from_array(nums);
    std::cout << result << std::endl;

    return 0;
}