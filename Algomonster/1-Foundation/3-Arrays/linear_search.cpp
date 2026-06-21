#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> numbers = {3, 8, 1, 7, 5};
    int result = linearSearch(numbers, 7);
    cout << result << endl;  // Output: 3

    // Searching for non-existent element
    result = linearSearch(numbers, 9);
    cout << result << endl;  // Output: -1 (not found)

    return 0;
}