#include <iostream>
#include <string>
#include <vector>

using namespace std;

// bool anagram_check(const string &a, const string &b) {
//     // lengths don't match
//     if (a.length() != b.length()) {
//         return false;
//     }

//     int freqs[26] = {0};
//     // build with a
//     for (char c : a) {
//         freqs[c - 'a']++;
//     }

//     // decrement with b
//     for (char d : b) {
//         if (--freqs[d - 'a'] < 0) {
//             return false;
//         }
//     }

//     return true;
// }

std::vector<int> find_all_anagrams(std::string &original, std::string &check) {
    if (original.length() < check.length())
        return {};

    vector<int> res;
    int tail = 0, head = check.length() - 1; // indices pointing to start/end

    int wish_list[26] = {0}, wish_count = 0;

    // initialise wish list with check - add everything to wish
    for (char c : check) {
        wish_list[c - 'a']++;
        wish_count++;
    }

    // decrement with initial
    for (int i = 0; i <= head; i++) {
        int c = original[i] - 'a';
        if (wish_list[c] > 0) { // reduce count if on list
            wish_count--;
        }
        wish_list[c]--;
    }

    if (wish_count == 0) {
        res.push_back(0);
    }

    // something might be wrong here
    int x, y = original[tail];
    while (head < original.length() - 1) {
        // move head forwards
        head++;
        x = original[head] - 'a'; // new char -> index
        if (wish_list[x] > 0) {   // if it's one of the wishes
            wish_count--;
        }
        wish_list[x]--;

        // move tail forwards
        if (wish_list[y - 'a'] >= 0) {
            wish_count++;
        }
        wish_list[y - 'a']++;
        tail++;
        y = original[tail];

        // check for anagram
        if (wish_count == 0) {
            res.push_back(tail);
        }
    }

    return res;
}

void pprint(std::vector<int> rotated) {
    for (int x : rotated) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}

int main() {
    string str1 = "cbaebabacd", str2 = "abc";
    vector<int> res = find_all_anagrams(str1, str2);
    pprint(res);
    return 0;
}