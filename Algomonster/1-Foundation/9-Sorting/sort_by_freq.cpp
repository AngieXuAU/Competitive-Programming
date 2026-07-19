#include <algorithm>
#include <iostream>
#include <string>

std::string sort_by_frequency(std::string &s) {
    // (1) create array
    int freqs[256] = {0};

    // (2) add frequency mappings
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        freqs[(int)uc]++;
    }

    // (3) sort the array
    std::sort(std::begin(freqs), std::end(freqs));

    // construct new string
    std::string result = "";
    return "";
}

int main() {
    std::string str = "tree";
    sort_by_frequency(str);

    std::cout << "Result: " << str << std::endl;
    return 0;
}

// Task Description:
// Given a string, return a new string with characters sorted by their
// frequency. Characters that appear more frequently should come first. When two
// characters have the same frequency, sort them alphabetically.