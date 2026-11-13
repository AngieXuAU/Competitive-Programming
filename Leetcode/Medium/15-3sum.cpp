#include <algorithm>
#include <iostream>
// #include <unordered_set>
#include <vector>

using namespace std;

template <class T> void pprint(const vector<T> &vec) {
    for (T x : vec) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}

vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end(),
         [](const auto &a, const auto &b) { return a < b; });

    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int a = nums[i];
        int lo = i + 1, hi = nums.size() - 1;

        while (lo < hi) {
            int sum = nums[lo] + nums[hi] + a;
            if (sum < 0) {
                lo++;
            } else if (sum > 0) {
                hi--;
            } else {
                vector<int> tmp = {a, nums[lo], nums[hi]};
                // cout << "adding: ";
                // pprint(tmp);
                result.push_back({a, nums[lo], nums[hi]});
                lo++;
                hi--;
                while (lo < hi && nums[lo] == nums[lo - 1]) {
                    lo++;
                }
            }
        }
    }
    // vector<vector<int>> output(result.begin(), result.end());
    return result;
}

int main() {
    // int cases;
    // cin >> cases;

    // int len, x;
    // for (int i = 0; i < cases; i++) {
    //     vector<int> tmp;
    //     cin >> len;
    //     for (int j = 0; j < len; j++) {
    //         cin >> x;
    //         tmp.push_back(x);
    //     }
    //     vector<vector<int>> io = threeSum(tmp);
    //     for (vector<int> vec : io) {
    //         pprint(vec);
    //     }
    // }

    vector<int> tmp = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> io = threeSum(tmp);
    for (vector<int> vec : io) {
        pprint(vec);
    }
}