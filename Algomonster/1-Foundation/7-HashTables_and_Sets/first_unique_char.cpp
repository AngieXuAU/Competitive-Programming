
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

int first_unique_character(const std::string &s) {
    // construct map key = ascii of character, value = index or -1 if repeated
    int indexes[256];
    std::fill(indexes, indexes + 256, -1);

    std::unordered_set<char> seen;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (seen.contains(c)) {
            indexes[(int)c] = -1;
        } else {
            indexes[(int)c] = i;
            seen.insert(c);
        }
    }

    // find minimum index
    int min_index = s.size();
    for (int j = 0; j < 256; j++) {
        if (indexes[j] == -1) {
            continue;
        } else if (indexes[j] < min_index) {
            min_index = indexes[j];
        }
    }

    // if min_index = s.size() then it passed through all 256 with -1 meaning no
    // uniques
    return ((min_index == s.size()) ? -1 : min_index);
}

int main() {
    std::string s1 = "leetcode";
    std::string s2 = "loveleetcode";
    std::string s3 = "aabb";

    std::cout << first_unique_character(s1) << "\t"
              << first_unique_character(s2) << "\t"
              << first_unique_character(s3) << "\t";
    return 0;
}