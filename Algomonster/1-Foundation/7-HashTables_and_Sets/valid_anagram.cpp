
#include <iostream>
#include <string>
#include <unordered_map>
// #include <vector>
// #include <algorithm>

bool valid_anagram(std::string s, std::string t) {
    // false if their lengths don't match
    if (s.size() != t.size()) {
        return false;
    }

    std::unordered_map<char, int> freqs = {};
    // construct frequency map from s
    for (char c : s) {
        freqs[c]++;
    }
    // deconstruct using t
    for (char c2 : t) {
        if (freqs[c2] > 0) {
            freqs[c2]--;
        } else {
            return false; // freqs[c2] defaults to 0
        }
    }

    return true;
}

int main() {
    std::string s1 = "hello";
    std::string t1 = "world";
    std::string s2 = "aab";
    std::string t2 = "aba";
    std::string s3 = "rat";
    std::string t3 = "car";
    std::string s4 = "listen";
    std::string t4 = "silent";

    std::cout << "Test 1: " << valid_anagram(s1, t1) << std::endl;
    std::cout << "Test 2: " << valid_anagram(s2, t2) << std::endl;
    std::cout << "Test 3: " << valid_anagram(s3, t3) << std::endl;
    std::cout << "Test 4: " << valid_anagram(s4, t4) << std::endl;

    return 0;
}