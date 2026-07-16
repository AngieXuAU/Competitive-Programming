
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> count_frequencies(std::vector<int> &arr) {
    std::unordered_map<int, int> frequencies = {};

    for (int x : arr) {
        frequencies[x]++;
    }

    return frequencies;
}

void pprint(std::unordered_map<int, int> dict) {
    std::cout << "\n{" << std::endl;
    for (const auto &[key, value] : dict) {
        std::cout << "'" << key << "'" << ": " << "'" << value << "'"
                  << std::endl;
    }
    std::cout << "}";
}

int main() {
    std::vector<int> arr1 = {1, 2, 2, 3, 3, 3};
    std::vector<int> arr2 = {5, 5, 5, 5};
    std::vector<int> arr3 = {1, 2, 3, 4};

    pprint(count_frequencies(arr1));
    pprint(count_frequencies(arr2));
    pprint(count_frequencies(arr3));

    return 0;
}