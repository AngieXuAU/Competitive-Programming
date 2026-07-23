#include <algorithm>
#include <iostream>
#include <vector>

int max_product_of_three(std::vector<int> &nums) {
    int length = nums.size();

    // quick exit for edge case
    if (length == 3) {
        return (nums[length - 3] * nums[length - 2] * nums[length - 1]);
    }

    std::sort(nums.begin(), nums.end());
    // return largest three if only one negative
    int count_negs = 0;
    for (int x : nums) {
        if (x < 0) {
            count_negs++;
        }
    }

    if (count_negs <= 1) {
        return (nums[length - 3] * nums[length - 2] * nums[length - 1]);
    }

    // we have at least 2 negs and at least 4 total
    // atp if size = 4 then 2 pos 2 neg
    // the product has to have at least one neg so u better use both to make it
    // pos then pick the larger positive number
    if (length == 4) {
        return (nums[0] * nums[1] * nums[3]);
    }

    // now we have at least 5
    int neg_prod = nums[0] * nums[1];
    int pos_prod = nums[2] * nums[3];
    int prod = (pos_prod > neg_prod) ? pos_prod : neg_prod;
    return prod * nums[4];
}

int main() {
    std::vector<int> nums = {-4, -3, 1, 2, 3};

    std::cout << max_product_of_three(nums);
    return 0;
}