#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string sort_by_frequency(std::string &s) {
    // (1) create array
    std::map<char, int> freq_map;

    // (2) add frequency mappings
    for (char c : s) {
        freq_map[c]++;
    }

    // (3) map -> vector(pairs) --> sort the vector
    std::vector<std::pair<char, int>> vec(freq_map.begin(), freq_map.end());
    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return ((a.second == b.second) ? (a.first < b.first)
                                       : (a.second > b.second));
    });

    // tiebreaking syntax in c++ 20
    // std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
    //     return std::tie(b.second, a.first) < std::tie(b.first, a.second);
    // });

    // construct new string
    std::string result = "";
    for (std::pair p : vec) {
        for (int i = 0; i < p.second; i++) {
            result += p.first;
        }
    }

    return result;
}

int main() {
    std::string str = "Aabb";
    std::string res = sort_by_frequency(str);

    std::cout << "Result: " << res << std::endl;
    return 0;
}

// Task Description:
// Given a string, return a new string with characters sorted by their
// frequency. Characters that appear more frequently should come first. When two
// characters have the same frequency, sort them alphabetically.