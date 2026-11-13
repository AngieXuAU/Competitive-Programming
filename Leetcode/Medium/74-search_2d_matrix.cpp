#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> getCoords(const int &index, const int &m) {
    return {index / m, index % m};
}

bool searchMatrix(vector<vector<int>> matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int min = 0, max = m * n - 1, mid;

    while (min <= max) {
        mid = min + (max - min) / 2;
        // cout << "mid: " << mid << "\n";
        pair<int, int> p = getCoords(mid, n);
        int x = matrix[p.first][p.second];

        // cout << "checking: " << x << "\t [at: " << "(" << p.first << ", "
        //      << p.second << ")]\n";
        if (x == target) {
            return true;
        } else if (x < target) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return false;
}

int main() {
    // for (int i = 0; i < 12; i++) {
    //     pair<int, int> p = getCoords(i, 4);
    //     cout << i << " is at: " << p.first << '\t' << p.second << '\n';
    // }
    cout << searchMatrix({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3)
         << '\n';
    cout << searchMatrix({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13)
         << '\n';
    cout << searchMatrix({{1}}, 0) << '\n';
    cout << searchMatrix({{1}}, 2) << '\n';

    return 0;
}

// tags: binary_search