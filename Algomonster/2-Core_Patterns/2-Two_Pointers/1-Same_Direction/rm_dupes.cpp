#include <iostream>
#include <vector>

using namespace std;

void pprint(vector<int> arr) {
    for (int x : arr) {
        cout << x << "\t";
    }
    cout << endl;
}

int remove_duplicates(std::vector<int> &arr) {
    // edge case: 1 value, must be unique
    if (arr.size() == 1) {
        return 1;
    }

    int i = 0, j = 1;

    while (j < arr.size() - 1) {
        while (j < arr.size() - 1 && arr[i] == arr[j]) {
            j++;
        }
        i++; // point i to the value to be overridden
        arr[i] = arr[j];
    }
    arr.resize(i + 1);

    if (arr[arr.size() - 1] == arr[arr.size() - 2]) {
        arr.pop_back();
    }
    return arr.size();
}

int main() {
    vector vec = {0, 0, 1, 1, 1, 2, 2};
    cout << remove_duplicates(vec) << "\n";
    pprint(vec);
    return 0;
}