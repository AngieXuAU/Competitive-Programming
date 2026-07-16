#include <iostream>
#include <queue>

int find_winner(int n, int k) {

    // create the queue
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    // rotate and eliminate
    while (q.size() > 1) {
        for (int j = 1; j < k; j++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int removed = q.front();
        std::cout << "Removed: " << removed << "\t";
        q.pop();
    }

    return q.front();
}

int main() {
    int winner = find_winner(5, 2);
    int winner2 = find_winner(6, 3);
    int winner3 = find_winner(1, 1);
    std::cout << std::endl
              << "Winners: " << winner << "\t" << winner2 << "\t" << winner3
              << "\t";
    return 0;
}