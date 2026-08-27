#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums;
        }

        if (nums.size() == 2) {
            // return if already ascending
            if (nums[0] <= nums[1]) {
                return nums;
            }
            // swap
            int tmp = nums[1];
            nums[1] = nums[0];
            nums[0] = tmp;
            return nums;
        }

        // split in half and sort then combine
        auto middle = nums.begin();
        for (int i = 0; i < nums.size() / 2; i++) {
            middle++;
        }

        vector<int> first(nums.begin(), middle);
        vector<int> second(middle, nums.end());

        sortArray(first);
        sortArray(second);

        nums.clear();

        int i = 0, j = 0;
        while (i < first.size() ||
               j < second.size()) { // could optimise with a lambda function
            if (i >= first.size()) {
                nums.push_back(second[j]);
                j++;
                continue;
            } else if (j >= second.size()) {
                nums.push_back(first[i]);
                i++;
                continue;
            }

            // add the smaller value
            if (first[i] <= second[j]) {
                nums.push_back(first[i]);
                i++;
            } else {
                nums.push_back(second[j]);
                j++;
            }
        }

        return nums;
    }
};