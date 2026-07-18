## 2026-07-16 — Valid Anagram (Algomonster)
tags: hashmap, array, frequency counting, space complexity, pass-by-reference
mistake: Used `std::unordered_map<char, int>` for frequency counting when the character set is fixed (ASCII), adding unnecessary hashing overhead. Also passed `std::string` by value instead of by `const` reference, causing unnecessary copies.
fix: Replaced `std::unordered_map` with a fixed-size `int freqs[256] = {0}` array, using ASCII values as direct indices to eliminate hashing. Identified that space complexity is O(1) (not O(U)) since the alphabet size is a constant bound. Should also update function signature to `const std::string& s, const std::string& t` to avoid copying.

## 2026-07-16 — Two Sum (Algomonster)
tags: hashmap, time complexity, c++23, iterator-invalidation
mistake: Swapped the condition and increment parts of the for-loop. Additionally, used a nested loop iterating over the map instead of a direct key lookup, which degraded performance to O(N^2) and risked iterator invalidation from modifying the map while traversing it.
fix: Corrected the for-loop structure. Replaced the nested loop with direct key lookup using `.contains()` and `.at()`, achieving O(N) time complexity and eliminating the risk of undefined behavior.

## 2026-07-16 — First Unique Character (Algomonster)
tags: array, hashmap, space complexity, signed-char-index, undefined-behavior
mistake: Used both `std::unordered_set<char>` and an `int indexes[256]` array, leading to redundant space usage and dynamic heap allocation overhead. Also indexed the array directly using `(int)c` without checking for signed char conversion, risking undefined behavior (negative index) if non-ASCII or extended characters were encountered.
fix: Removed `std::unordered_set` entirely by using a state machine inside the array: `-1` for unseen, `i >= 0` for seen once, and `-2` for seen multiple times. Prevented negative indexing by casting the `char` to `unsigned char` before indexing. This guaranteed strict O(N) time complexity (no hash collision risk) and O(1) space complexity.

## 2026-07-16 — Array Intersection (Algomonster)
tags: hashmap, two-pointer, space complexity, pass-by-value, infinite-loop
mistake: Used `std::unordered_map` for the intersection, resulting in O(N) auxiliary space and vulnerability to O(N^2) worst-case time due to hash collisions. When trying to implement the two-pointer approach, got stuck in an infinite loop because pointers were not incremented when matching elements were found. Also passed vector parameters by value to the print helper.
fix: Transitioned to a sorted two-pointer approach, reducing auxiliary space to O(1) and guaranteeing O(M + N) time complexity. Handled matches by incrementing both pointers `i` and `j` to avoid infinite loops. Optimized the printing helper signature to pass the vector by `const` reference.

## 2026-07-17 — Remove Adjacent Duplicates (Algomonster)
tags: stack, string, space complexity, std::string-as-stack
mistake: Used `std::stack<char>` to simulate the stack, then drained it into a separate `std::string` and called `std::reverse()` to produce the result. This incurred an extra O(N) pass and allocated two separate data structures.
fix: Replaced `std::stack<char>` with `std::string result` used directly as a stack via `push_back()`, `pop_back()`, and `back()`. Since `std::string` stores elements in order, the result is already in the correct forward order when returned, eliminating the drain loop and the `std::reverse()` call entirely. Time and space complexity remain O(N) but constant factors are improved.

## 2026-07-18 — Backspace String Compare (Algomonster)
tags: stack, two-pointer, space complexity, out-of-range, unsigned-integer-wrap, boundary-conditions
mistake: Initial stack-based approach used O(N + M) auxiliary space. When attempting the O(1) space two-pointer optimisation, several bugs were introduced: (1) `tptr` was initialised using `s.size()` instead of `t.size()`; (2) character variables `x`/`y` were not updated after decrementing pointers inside the inner skip loop, causing infinite loops; (3) the comparison was performed before skipping backspaces; (4) the boundary check for negative pointers was placed before calling `get_next_valid_index`, preventing strings like `"a##c"` from being correctly recognised as exhausted after skipping; (5) passing a negative `int` index to `std::string::at()` caused it to wrap to a huge unsigned value (`18446744073709551615`), throwing `std::out_of_range`.
fix: Extracted the skip logic into a helper `get_next_valid_index(str, index)` that walks backwards past `#` characters and their targets, returning `-1` when the string is fully consumed. In the main loop: call the helper on both pointers first, then check if both are `< 0` (equal, break), one is `< 0` (unequal, return false), otherwise compare `s[sptr]` and `t[tptr]` directly before decrementing. This achieves O(N + M) time and O(1) auxiliary space.
