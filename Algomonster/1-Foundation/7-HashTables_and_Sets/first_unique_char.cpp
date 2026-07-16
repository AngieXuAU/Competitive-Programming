
#include <algorithm>
#include <iostream>
#include <string>

int first_unique_character(const std::string &s) {
    // construct map key = ascii of character, value = index or -1 if repeated
    int indexes[256];
    std::fill(indexes, indexes + 256,
              -1); // default -1: not seen | -2: seen multiple times

    for (int i = 0; i < s.size(); i++) { // loop through given string
        char c = s[i];
        unsigned char uc = c; // force integer casting to be positive
        int ascii = (int)uc;

        if (indexes[ascii] == -2) {
            continue; // skip if already seen multiple times
        } else if (indexes[ascii] == -1) { // if not already seen
            indexes[ascii] = i;            // set value to index
        } else {                           // already seen once
            indexes[ascii] = -2;
        }
    }

    // find minimum index
    int min_index = s.size();
    for (int j = 0; j < 256; j++) {
        if (indexes[j] < 0) {
            continue; // either not seen or seen multiple times
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