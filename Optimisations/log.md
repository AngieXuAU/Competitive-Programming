## 2026-07-16 — Valid Anagram (Algomonster)
tags: hashmap, array, frequency counting, space complexity, pass-by-reference
mistake: Used `std::unordered_map<char, int>` for frequency counting when the character set is fixed (ASCII), adding unnecessary hashing overhead. Also passed `std::string` by value instead of by `const` reference, causing unnecessary copies.
fix: Replaced `std::unordered_map` with a fixed-size `int freqs[256] = {0}` array, using ASCII values as direct indices to eliminate hashing. Identified that space complexity is O(1) (not O(U)) since the alphabet size is a constant bound. Should also update function signature to `const std::string& s, const std::string& t` to avoid copying.

## 2026-07-16 — Two Sum (Algomonster)
tags: hashmap, time complexity, c++23, iterator-invalidation
mistake: Swapped the condition and increment parts of the for-loop. Additionally, used a nested loop iterating over the map instead of a direct key lookup, which degraded performance to O(N^2) and risked iterator invalidation from modifying the map while traversing it.
fix: Corrected the for-loop structure. Replaced the nested loop with direct key lookup using `.contains()` and `.at()`, achieving O(N) time complexity and eliminating the risk of undefined behavior.
