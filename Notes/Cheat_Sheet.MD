# Competitive Programming Beginner Cheat Sheet (C++)

## 1. The Core C++ Template
This template includes all the standard libraries, sets up fast input/output (crucial for passing time limits), and provides some handy aliases.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
// #include <bits/stdc++.h>
using namespace std;

// Aliases for less typing
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

// Macros for loops and common operations
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

void solve() {
    // Your code for a single test case goes here
    
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // File I/O (Uncomment if the problem requires reading/writing to files)
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t; // Remove this if the problem only has one test case
    while (t--) {
        solve();
    }
    return 0;
}
```

## 2. Binary Search Template
Binary search is incredibly common, not just for finding elements, but for "binary searching the answer". This template helps avoid off-by-one errors.

```cpp
bool check(int mid) {
    // Return true if the condition is satisfied at 'mid'
    return true; 
}

int binarySearch(int low, int high) {
    int ans = -1; // Or default value if not found
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            // Depending on what you are looking for:
            high = mid - 1; // If you want the FIRST (smallest) valid 'mid'
            // low = mid + 1; // If you want the LAST (largest) valid 'mid'
        } else {
            // Adjust bounds based on monotonic property
            low = mid + 1; // Or high = mid - 1;
        }
    }
    return ans;
}
```

## 3. Graph Traversals (DFS & BFS)
Many beginner/intermediate problems can be modeled as graphs. 

### Depth First Search (DFS)
Good for exploring all paths, checking connectivity, or finding components.

```cpp
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

### Breadth First Search (BFS)
Good for finding the shortest path in an unweighted graph.

```cpp
void bfs(int start) {
    queue<int> q;
    vector<int> dist(MAXN, -1); // -1 means unvisited
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}
```

## 4. Prefix Sums (1D)
Extremely useful when you need to repeatedly find the sum of elements in a range array `[L, R]`.

```cpp
// Building the prefix sum array
vector<int> a = {2, 4, 1, 5, 3};
int n = a.size();
vector<int> pref(n + 1, 0); // 1-indexed is easier
for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
}

// Querying the sum from index L to R (0-indexed in original array)
// Query sum of a[L...R]:
// int sum = pref[R + 1] - pref[L];
```

## 5. Sorting & Custom Comparators
Often you'll need to sort pairs or custom structs.

```cpp
struct Item {
    int weight, value;
};

// Sort by value ascending, then by weight descending
bool customSort(Item a, Item b) {
    if (a.value != b.value) {
        return a.value < b.value;
    }
    return a.weight > b.weight;
}

// Usage:
// vector<Item> items = ...
// sort(items.begin(), items.end(), customSort);
```

---

## Python Quick Reference (Backup)

For simpler problems or when fast prototyping is preferred over C++.

### Fast I/O & Recursion Setup
```python
import sys
from collections import deque, defaultdict, Counter
import heapq
import bisect

# Increase recursion limit for deep DFS
sys.setrecursionlimit(200000)

def solve():
    # Fast line reader alias:
    # input = sys.stdin.readline
    
    # Fast full token reader:
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    n = int(next(it))
    arr = [int(next(it)) for _ in range(n)]

if __name__ == '__main__':
    solve()
```

### Essential Data Structures & Syntax

```python
# 1. Deque (Queue / BFS / Stack)
q = deque([start])
q.append(val)
curr = q.popleft()  # O(1) pop from front

# 2. Min-Heap & Max-Heap
heap = []
heapq.heappush(heap, val)
min_val = heapq.heappop(heap)
# Max-Heap trick: push -val, retrieve with -heapq.heappop(heap)

# 3. Binary Search (bisect)
# arr must be sorted
idx1 = bisect.bisect_left(arr, target)   # First index where elem >= target
idx2 = bisect.bisect_right(arr, target)  # First index where elem > target

# 4. Hash Map & Frequency Counting
freq = Counter(arr)          # freq[x] -> count of x
graph = defaultdict(list)    # Adjacency list: graph[u].append(v)

# 5. Grid Initialization (2D Array)
rows, cols = 5, 5
grid = [[0] * cols for _ in range(rows)]  # Avoid [[0]*cols]*rows !

# 6. Custom Sorting
# Sort by first element ascending, second element descending
items.sort(key=lambda x: (x[0], -x[1]))
```

------------------

