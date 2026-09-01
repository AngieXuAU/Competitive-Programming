#include <vector>

using namespace std;

class Solution {
  private:
    // Helper function that sorts nums in the range [left, right] (inclusive)
    void mergeSort(vector<int> &nums, vector<int> &temp, int left, int right) {
        // Base case: If the range has 0 or 1 element, it is already sorted.
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid + 1, right);

        merge(nums, temp, left, mid, right);
    }

    void merge(vector<int> &nums, vector<int> &temp, int left, int mid,
               int right) {
        for (int k = left; k <= right; k++) {
            temp[k] = nums[k];
        }

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                nums[k] = temp[i];
                i++;
            } else {
                nums[k] = temp[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            nums[k] = temp[i];
            i++;
            k++;
        }
    }

  public:
    vector<int> sortArray(vector<int> &nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};
