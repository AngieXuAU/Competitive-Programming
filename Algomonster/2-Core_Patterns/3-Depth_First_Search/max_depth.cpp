#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// u: current node
// p: parent node (to avoid going back up the tree)
// adj: adjacency list representing the tree

int tree_max_depth(int u, int p, const vector<vector<int>> &adj) {
    // TODO: Implement the logic to find the maximum depth
    // of the tree using the adjacency list.

    return 0;
}

void solve() {
    int n;
    if (!(cin >> n))
        return;

    // In competitive programming, trees are usually 1-indexed.
    // We allocate n + 1 so we can directly use the node labels 1..n.
    vector<vector<int>> adj(n + 1);

    // A tree with n nodes has n - 1 edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Assuming the tree is rooted at node 1.
    // The parent of the root can be passed as 0 (or -1) since it doesn't exist.
    int res = tree_max_depth(1, 0, adj);
    cout << res << '\n';
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}