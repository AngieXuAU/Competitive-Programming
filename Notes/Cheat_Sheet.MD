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

---

## Data Type Size & Range Limitations (C++)

### Integer Types

| Data Type | Bit Width | Byte Size | Minimum Value | Maximum Value | Scientific / Approx. Range |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `int` | 32 bits | 4 B | `-2,147,483,648` (-2³¹) | `2,147,483,647` (2³¹ - 1) | ≈ ±2.14 × 10⁹ |
| `unsigned int` | 32 bits | 4 B | `0` | `4,294,967,295` (2³² - 1) | ≈ 4.29 × 10⁹ |
| `long` | 32 / 64 bits | 4 / 8 B | Win: `-2,147,483,648`<br>Linux 64: `-9,223,372,036,854,775,808` | Win: `2,147,483,647`<br>Linux 64: `9,223,372,036,854,775,807` | ≈ ±2.14 × 10⁹ (Win)<br>≈ ±9.22 × 10¹⁸ (Linux) |
| `unsigned long` | 32 / 64 bits | 4 / 8 B | `0` | Win: `4,294,967,295`<br>Linux 64: `18,446,744,073,709,551,615` | ≈ 4.29 × 10⁹ (Win)<br>≈ 1.84 × 10¹⁹ (Linux) |
| `long long` | 64 bits | 8 B | `-9,223,372,036,854,775,808` (-2⁶³) | `9,223,372,036,854,775,807` (2⁶³ - 1) | ≈ ±9.22 × 10¹⁸ |
| `unsigned long long` | 64 bits | 8 B | `0` | `18,446,744,073,709,551,615` (2⁶⁴ - 1) | ≈ 1.84 × 10¹⁹ |
| `__int128` (GCC extension) | 128 bits | 16 B | ≈ -1.70 × 10³⁸ (-2¹²⁷) | ≈ 1.70 × 10³⁸ (2¹²⁷ - 1) | ≈ ±1.70 × 10³⁸ |

### Character Types

| Data Type | Bit Width | Byte Size | Minimum Value | Maximum Value | Scientific / Approx. Range | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `char` | 8 bits | 1 B | `-128` or `0` | `127` or `255` | ≈ 10² | Default char type (signed on x86 GCC/MSVC, unsigned on ARM) |
| `signed char` | 8 bits | 1 B | `-128` (-2⁷) | `127` (2⁷ - 1) | ≈ ±10² | Explicitly signed byte |
| `unsigned char` | 8 bits | 1 B | `0` | `255` (2⁸ - 1) | ≈ 2.55 × 10² | Explicitly unsigned byte |
| `wchar_t` | 16 / 32 bits | 2 / 4 B | Win: `0` / `-32,768`<br>Linux: `-2,147,483,648` | Win: `65,535` / `32,767`<br>Linux: `2,147,483,647` | ≈ 6.55 × 10⁴ (Win)<br>≈ ±2.14 × 10⁹ (Linux) | Wide character representation |
| `char8_t` (C++20) | 8 bits | 1 B | `0` | `255` | ≈ 2.55 × 10² | UTF-8 code unit |
| `char16_t` | 16 bits | 2 B | `0` | `65,535` (2¹⁶ - 1) | ≈ 6.55 × 10⁴ | UTF-16 code unit |
| `char32_t` | 32 bits | 4 B | `0` | `4,294,967,295` (2³² - 1) | ≈ 4.29 × 10⁹ | UTF-32 code unit / Unicode scalar |

### Floating-Point Types

| Data Type | Bit Width | Byte Size | Precision | Min Positive Value | Max Value | Scientific / Approx. Range |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `float` | 32 bits | 4 B | ~6–7 decimal digits | ≈ 1.175 × 10⁻³⁸ | ≈ 3.402 × 10³⁸ | ≈ ±3.40 × 10³⁸ |
| `double` | 64 bits | 8 B | ~15–17 decimal digits | ≈ 2.225 × 10⁻³⁰⁸ | ≈ 1.797 × 10³⁰⁸ | ≈ ±1.80 × 10³⁰⁸ |
| `long double` | 80 / 128 bits | 10–16 B | ~18–19 digits (80-bit x87)<br>~34 digits (IEEE 128-bit) | ≈ 3.362 × 10⁻⁴⁹³² | ≈ 1.189 × 10⁴⁹³² | ≈ ±1.19 × 10⁴⁹³² |

### Quick CP Rules of Thumb
- **10⁹**: Fits in standard 32-bit `int` (max ≈ 2.14 × 10⁹).
- **10¹⁸**: Requires 64-bit `long long` (max ≈ 9.22 × 10¹⁸).
- **10³⁸**: Requires `__int128` (GCC extension).
- **Exact Floating Precision**: `double` preserves exact integer values up to 2⁵³ ≈ 9 × 10¹⁵.


------------------

By linearity of expectation, after $n$ weeks, the total expected score is simply: $$\text{Expected Score} = \text{start} + n \times \frac{\text{worse} - \text{better}}{100.0}$$

For l: $1 + 10 \times \frac{50 - 10}{100.0} = 1 + 10 \times 0.4 = 5.0$
For t: $2 + 10 \times \frac{0 - 80}{100.0} = 2 + 10 \times (-0.8) = -6.0$
For cobra: $3 + 10 \times \frac{20 - 20}{100.0} = 3.0$
