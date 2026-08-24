# Competitive Programming Advanced Cheat Sheet (C++ & Python)

This cheat sheet covers intermediate-to-advanced algorithms, data structures, and math utilities commonly used in competitive programming.

---

## 1. Number Theory & Modular Arithmetic

### Modular Exponentiation ($O(\log \text{exp})$)
Computes $(a^b) \pmod m$ efficiently without integer overflow.

**C++:**
```cpp
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}
```

**Python:**
```python
# Built-in 3-argument pow is O(log exp) and handles arbitrary precision
res = pow(base, exp, mod)
```

---

### GCD, LCM & Modular Inverse
Find Greatest Common Divisor, Least Common Multiple, and Modular Multiplicative Inverse via Fermat's Little Theorem (requires prime `mod`).

**C++:**
```cpp
#include <numeric> // Required for std::gcd and std::lcm (C++17+)

long long g = std::gcd(a, b);
long long l = std::lcm(a, b);

// Modular Inverse: a^(-1) % mod = pow(a, mod - 2, mod) when mod is prime
long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}
```

**Python:**
```python
import math

g = math.gcd(a, b)
l = math.lcm(a, b)  # Python 3.9+

# Built-in Modular Inverse (Python 3.8+)
inv = pow(a, -1, mod)
```

---

### Sieve of Eratosthenes ($O(N \log \log N)$)
Precomputes prime numbers up to $N$.

**C++:**
```cpp
const int MAXN = 1e7;
vector<bool> is_prime(MAXN + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAXN; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                is_prime[i] = false;
        }
    }
}
```

---

## 2. C++ STL Advanced Searching & Heaps

### Binary Search Functions (`lower_bound` / `upper_bound`)
* `lower_bound`: Returns iterator to first element $\ge \text{target}$ (`bisect_left`).
* `upper_bound`: Returns iterator to first element $> \text{target}$ (`bisect_right`).

```cpp
vector<int> v = {10, 20, 30, 30, 40, 50};

// Find first element >= 30 (index 2)
auto it1 = lower_bound(v.begin(), v.end(), 30);
int idx1 = distance(v.begin(), it1);

// Find first element > 30 (index 4)
auto it2 = upper_bound(v.begin(), v.end(), 30);
int idx2 = distance(v.begin(), it2);

// Check if element exists
bool exists = (it1 != v.end() && *it1 == 30);
```

---

### Priority Queues (Min-Heap & Max-Heap)

```cpp
#include <queue>

// Max-heap (default)
priority_queue<int> max_pq;

// Min-heap
priority_queue<int, vector<int>, greater<int>> min_pq;

// Priority Queue with pairs (e.g. {distance, node} for Dijkstra)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

---

## 3. Disjoint Set Union (DSU / Union-Find)

Supports $O(\alpha(N))$ nearly $O(1)$ set union and find operations using path compression and union by size.

**C++:**
```cpp
struct DSU {
    vector<int> parent, sz;
    
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            return true;
        }
        return false;
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};
```

**Python:**
```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.sz = [1] * (n + 1)

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def unite(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            if self.sz[root_i] < self.sz[root_j]:
                root_i, root_j = root_j, root_i
            self.parent[root_j] = root_i
            self.sz[root_i] += self.sz[root_j]
            return True
        return False
```

---

## 4. Shortest Paths & Grid Utilities

### Dijkstra's Algorithm ($O((V + E) \log V)$)
Finds shortest paths from a source node in a weighted graph with non-negative edge weights.

**C++:**
```cpp
const int INF = 1e9 + 7;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

---

### Grid Traversal Helpers (`dx`, `dy`)

```cpp
// 4-Directional movement (Up, Down, Left, Right)
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool isValid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// Example usage inside BFS/DFS loop
for (int i = 0; i < 4; ++i) {
    int nr = r + dx[i];
    int nc = c + dy[i];
    if (isValid(nr, nc, rows, cols) && !visited[nr][nc]) {
        // Visit neighbor
    }
}
```

---

## 5. Subarray & Range Query Tricks

### Difference Array (Range Updates in $O(1)$)
Applies multiple range additions $[L, R] += x$ in $O(1)$ time, followed by an $O(N)$ prefix sum to compute final values.

**C++:**
```cpp
int n = 5;
vector<int> diff(n + 2, 0);

// Add val to range [L, R] (1-indexed)
void rangeUpdate(int L, int R, int val) {
    diff[L] += val;
    diff[R + 1] -= val;
}

// Reconstruct original array after all queries
vector<int> getFinalArray() {
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        a[i] = diff[i];
    }
    return a;
}
```

---

### 2D Prefix Sums (Submatrix Range Query in $O(1)$)

```cpp
int rows = grid.size(), cols = grid[0].size();
vector<vector<int>> pref(rows + 1, vector<int>(cols + 1, 0));

// 1. Build 2D Prefix Sum Array
for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        pref[r + 1][c + 1] = grid[r][c] + pref[r][c + 1] 
                            + pref[r + 1][c] - pref[r][c];
    }
}

// 2. Query Submatrix Sum from (r1, c1) to (r2, c2) 0-indexed
int query2D(int r1, int c1, int r2, int c2) {
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] 
         - pref[r2 + 1][c1] + pref[r1][c1];
}
```

---

## 6. Bit Manipulation & Built-ins

### C++ GCC Built-ins
```cpp
long long x = 44; // Binary: 101100

int set_bits = __builtin_popcountll(x); // Count '1's -> 3
int leading_zeros = __builtin_clzll(x); // Count leading zeros
int trailing_zeros = __builtin_ctzll(x); // Count trailing zeros -> 2
```

### Essential Bitwise Operations
```cpp
// Check if i-th bit is set
bool is_set = (x & (1LL << i)) != 0;

// Set i-th bit
x |= (1LL << i);

// Clear i-th bit
x &= ~(1LL << i);

// Toggle i-th bit
x ^= (1LL << i);

// Extract lowest set bit (LSB)
long long lsb = x & -x;

// Check if power of two
bool is_pow2 = (x > 0) && ((x & (x - 1)) == 0);
```
## 7. Complete Search
### Generate all subsets
- Recursion
```cpp
int n = 3;

vector<int> subset;

void search(int k) {
    if (k == n) {
        for (int x : subset)
            cout << x << "\t";
        cout << "\n";
    } else {
        search(k + 1);
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
    }
}

int main() {
    search(0);
    return 0;
}
```

- Bitwise Manipulation
```cpp
for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
        if (b&(1<<i)) subset.push_back(i);
    }
}
```
Note `1<<n` uses 32-bit signed integer which will overflow if $n \geq31$. For larger (up to 62) use 64-bit literal: `1LL << n`.

### Generate permutations
```cpp
int n = 3;

vector<int> permutation;
bool chosen[3] = {false};

void search() {
    if (permutation.size() == n) {
        for (int x : permutation) {
            cout << x << "\t";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
```

#### Using built-in:
- permutation must be sorted, otherwise only generates lexicographically larger permutations
```cpp
vector<int> permutation;
for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}
do {
// process permutation
} while (next_permutation(permutation.begin(),permutation.end()));

```

### Backtracking

### Pruning the search

### Meet in the middle