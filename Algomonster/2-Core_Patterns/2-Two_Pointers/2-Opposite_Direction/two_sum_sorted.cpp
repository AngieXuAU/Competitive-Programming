#include <iostream>
#include <vector>
using namespace std;

std::vector<int> two_sum_sorted(std::vector<int> &arr, int target) {
    int front_ind = 0, back_ind = arr.size() - 1;

    while (front_ind < back_ind) {
        int sum = arr[front_ind] + arr[back_ind];
        if (sum == target) {
            return vector<int>{front_ind, back_ind};
        } else if (sum > target) {
            back_ind--;
        } else {
            front_ind++;
        }
    }
    return {};
}

void pprint(std::vector<int> rotated) {
    for (int x : rotated) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 8, 11, 18};

    pprint(two_sum_sorted(arr, 8));
}