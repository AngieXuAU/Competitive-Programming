
#include <iostream>
#include <unordered_set>
#include <vector>

bool contains_duplicate(std::vector<int> &nums) {

    std::unordered_set<int> uniques;
    for (int x : nums) {
        if ((uniques.find(x) == uniques.end()) || uniques.empty()) {
            uniques.insert(x);
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> test1 = {1, 2, 3, 4};
    std::vector<int> test3 = {1, 2, 3, 1};
    std::vector<int> test2 = {5, 5, 5};
    std::cout << contains_duplicate(test1) << "\t" << contains_duplicate(test2)
              << "\t" << contains_duplicate(test3);
    return 0;
}