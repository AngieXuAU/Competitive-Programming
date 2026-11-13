#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> result;
    unordered_map<int, int> freqs;

    for (int num : nums) {
        freqs[num]++;
    }

    vector<pair<int, int>> tmp(freqs.begin(), freqs.end());

    sort(tmp.begin(), tmp.end(),
         [](const auto &a, const auto &b) { return a.second > b.second; });

    for (int i = 0; i < k; i++) {
        result.push_back(tmp[i].first);
    }

    return result;
}

void pprint(std::vector<int> vec) {
    for (int x : vec) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}

int main() {
    int cases;
    cin >> cases;

    int k, len, x;
    for (int i = 0; i < cases; i++) {
        cin >> k >> len;
        vector<int> vec;
        for (int j = 0; j < len; j++) {
            cin >> x;
            vec.push_back(x);
        }
        pprint(topKFrequent(vec, k));
    }
    return 0;
}