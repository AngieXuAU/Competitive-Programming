#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string *>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string *>> groups;

    for (string str : strs) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());

        if (groups.contains(sorted)) {
            groups[sorted].push_back(&str);
        } else {
            groups[sorted] = {&str};
        }
    }

    vector<vector<string *>> result = {};
    for (const auto &[key, value] : groups) {
        result.push_back(value);
    }

    return result;
}

int main() {
    vector<string> test = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string *>> result = groupAnagrams(test);
}