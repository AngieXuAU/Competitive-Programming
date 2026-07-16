# Maps and Hashes in C++ (Competitive Programming)

In competitive programming, choosing the right map structure and understanding how hashes work under the hood is critical to avoiding compilation errors, sub-optimal performance, or Time Limit Exceeded (TLE) verdicts.

---

## 1. `std::unordered_map` vs. `std::map`

| Metric | `std::unordered_map` | `std::map` |
| :--- | :--- | :--- |
| **Underlying Structure** | Hash Table | Self-balancing Binary Search Tree (Red-Black Tree) |
| **Average Time Complexity** | $O(1)$ per operation | $O(\log N)$ per operation |
| **Worst-case Time Complexity** | $O(N)$ per operation (on hash collisions) | $O(\log N)$ per operation (guaranteed) |
| **Element Ordering** | No guaranteed order | Sorted by key |
| **Key Requirements** | Needs a hash function (`std::hash<Key>`) and equality operator (`==`) | Needs a comparison operator (`<`) |

### When to use which?
* Use **`std::unordered_map`** by default when you need fast $O(1)$ lookup, insertion, and deletion, and do not care about the order of keys.
* Use **`std::map`** when you need keys to be kept in sorted order, or when you need queries like "find the next largest key" (using `lower_bound` or `upper_bound`).

---

## 2. Hash Collisions & Adversarial Inputs (TLE Attacks)

When using `std::unordered_map`, keys are mapped to indices using a hash function. If two keys produce the same hash value, they are placed in the same bucket (a **hash collision**). 

In C++, the default hash function for integers is often the **identity function** (i.e., `hash(x) = x`). 

### The Problem
Adversarial test cases can exploit this simplicity. If a test case contains many integers that all hash to the same bucket modulo the hash map's size, lookup and insertion time degrades from $O(1)$ to $O(N)$. 
Doing this $N$ times results in a total runtime of **$O(N^2)$**, causing a **TLE** (Time Limit Exceeded) verdict.

---

## 3. Safe Custom Hash Implementation

To prevent adversarial test cases from triggering worst-case $O(N^2)$ behavior, you can define a **custom hash function** that uses:
1. A **fixed random seed** generated at runtime using a high-resolution clock (making the hash function unpredictable to test cases).
2. A **mixing function** (like `splitmix64`) to scramble the bits thoroughly.

### Template

```cpp
#include <chrono>
#include <unordered_map>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // A high-quality 64-bit mixer
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Usage:
// Pass custom_hash as the third template parameter
std::unordered_map<int, int, custom_hash> safe_map;
```

> [!TIP]
> Always use `custom_hash` when declaring an `std::unordered_map` or `std::unordered_set` with integer/long-long keys on platforms that allow custom test case generation (like Codeforces).
