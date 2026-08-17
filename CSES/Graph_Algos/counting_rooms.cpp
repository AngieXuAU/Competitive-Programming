#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    cin >> height >> width;
    int map[height][width];

    char tmp;
    // build input
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    int x = 0, y = 0;
    while (x + y < height + width - 2) {
    }

    return 0;
}

// You are given a map of a building, and your task is to count the number of
// its rooms. The size of the map is n \times m squares, and each square is
// either floor or wall. You can walk left, right, up, and down through the
// floor squares. Input The first input line has two integers n and m: the
// height and width of the map. Then there are n lines of m characters
// describing the map. Each character is either . (floor) or # (wall). Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3