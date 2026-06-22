# Methods

## Palindrome

- `std::string& s`
  - binds only to modifiable `std::string` lvalues
  - cannot bind to string literals or temporaries
- `const std::string& s`
  - binds to lvalues, temporaries, string literals
  - best for read-only palindrome checks
- `std::string s`
  - copies the string into the function
  - always valid if convertible to `std::string`

### Method 1: reverse + compare
- build reversed string explicitly
- compare reversed copy with original
- time: O(n)
- space: O(n)
- example: manual loop or `std::string rev(s.rbegin(), s.rend())`
- same algorithm as "reverse string then compare"

### Method 2: stack
- push first half into stack
- compare popped chars with second half
- time: O(n)
- space: O(n) (stack size ~ n/2 + copy)
- more overhead than reverse+compare
- not optimal compared to two-pointer / reverse iterators

### `std::equal` with reverse iterators
- `std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin())`
- compares left half to reversed right half
- time: O(n)
- extra space: O(1)
- same complexity as two-pointer method
- better than reverse+compare and stack because no extra storage

### Two-pointer compare
- compare `s[i]` with `s[n-1-i]`
- stop early on mismatch
- time: O(n)
- extra space: O(1)
- most optimal non-destructive check

### In-place reverse notes
- reversing a copy in place: O(n) time, O(n) space (copy exists)
- reversing original in place: O(n) time, O(1) extra space, but destroys input
- for `is_palindrome(std::string s)` the copy already exists, so in-place reverse on `s` is still O(n) space overall

### Summary
- best non-destructive: two-pointer or `std::equal` with `rbegin`
- reverse+compare: O(n) time, O(n) space
- stack: O(n) time, O(n) space, more overhead
- `std::string&` vs `const std::string&`: use `const std::string&` for string literals/temporaries

## Reverse Strings

- `std::string rev(s.rbegin(), s.rend())`
  - direct reverse-copy using reverse iterators
  - time: O(n), space: O(n)
  - avoids extra temporary copy if using `s` directly
- `std::string rev = s; std::reverse(rev.begin(), rev.end())`
  - reverse in place on a copy
  - time: O(n), space: O(n)
- manual reverse loop
  - same complexity: O(n) time, O(n) space
  - slightly more code, explicit character-by-character build
