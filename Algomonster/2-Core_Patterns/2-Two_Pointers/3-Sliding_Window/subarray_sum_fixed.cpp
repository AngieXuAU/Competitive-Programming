#include <iostream>
#include <vector>

using namespace std;

// Given an array (list) nums consisted of only non-negative integers, find the
// largest sum among all subarrays of length k in nums.

int subarray_sum_fixed(std::vector<int> &nums, int k) {
    int back_ind = 0, front_ind = k - 1;
    // initialise the sum
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int largest_sum = sum;
    while (front_ind < nums.size() - 1) {
        // move forwards
        front_ind++;
        sum += nums[front_ind];
        // slide the window
        sum -= nums[back_ind];
        back_ind++;

        // compare with largest sum
        largest_sum = (sum > largest_sum ? sum : largest_sum);
    }

    return largest_sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 7, 4, 1};
    cout << subarray_sum_fixed(nums, 3);
}