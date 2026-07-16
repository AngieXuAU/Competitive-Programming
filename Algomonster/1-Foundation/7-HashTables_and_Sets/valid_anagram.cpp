
#include <iostream>
#include <string>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>

bool valid_anagram(std::string s, std::string t) {
    // false if their lengths don't match
    if (s.size() != t.size()) {
        return false;
    }

    int freqs[256] = {0};

    // construct the frequency map using s
    for (char c : s) {
        freqs[(int)c]++;
    }

    // deconstruct using t
    for (char d : t) {
        if (freqs[(int)d] <= 0) {
            return false;
        }
        freqs[(int)d]--;
    }

    // make sure everything is 0
    for (int i = 0; i < 256; i++) {
        if (freqs[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s1 = "hello";
    std::string t1 = "hello";
    std::string s2 = "aab";
    std::string t2 = "aba";
    std::string s3 = "aab";
    std::string t3 = "abb";
    std::string s4 = "listen";
    std::string t4 = "silent";

    std::cout << "Test 1: " << valid_anagram(s1, t1) << std::endl;
    std::cout << "Test 2: " << valid_anagram(s2, t2) << std::endl;
    std::cout << "Test 3: " << valid_anagram(s3, t3) << std::endl;
    std::cout << "Test 4: " << valid_anagram(s4, t4) << std::endl;

    return 0;
}