#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> &arr) {
    int limit = arr.size();
    for (int i = 0; i < limit - 1; i++) { // i = first unchecked val
        int min_index = i;
        for (int j = i + 1; j < limit; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    return arr;
}

int main() {
    vector<int> numbers = {64, 25, 12, 22, 11};
    selectionSort(numbers);

    for (int num : numbers) {
        cout << num << " ";
    }
    // Output: 11 12 22 25 64

    return 0;
}