# String Methods

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
  - example: `for (int i = s.size()-1; i >= 0; --i) rev.push_back(s[i]);`

## Anagram

- Method 1: sort and compare
  - alphabetise both strings and compare the sorted sequences
  - time: O(n log n)
  - space: O(n)
  - simple and correct, but not optimal for large strings

- Method 2: remove matching letters
  - build a character list for the first string, then for each letter in the second string find and erase one matching entry
  - time: O(n^2)
  - space: O(n)
  - avoids sorting, but repeated search and erase make it slow for long inputs

- Method 3: count character frequencies
  - increment counts for `str1` and decrement counts for `str2`, then check that all counts are zero
  - time: O(n)
  - space: O(k) where `k` is the alphabet/domain size, often O(1) for fixed alphabets
  - the best general method for anagram checking when the alphabet is bounded

### Recommendation
- use Method 3 for best performance
- Method 1 is acceptable when input size is moderate and simplicity is desired
- avoid Method 2 in performance-sensitive code because it is quadratic

## Remove Vowels

### Containers
- prefer fixed, immutable vowel data over a mutable `std::vector<char>`
- `constexpr std::string_view vowels = "aeiouAEIOU";`
  - fixed at compile time
  - read-only sequence
  - supports `std::find(vowels.begin(), vowels.end(), c)`
- `constexpr std::array<char, 10> vowels = {'a','e','i','o','u','A','E','I','O','U'};`
  - fixed-size container
  - also supports `std::find(vowels.begin(), vowels.end(), c)`
- for maximum lookup speed, use a fixed boolean table:
  - `static constexpr std::array<bool, 256> is_vowel = ...;`
  - lookup by `is_vowel[static_cast<unsigned char>(c)]`
  - avoids searching entirely
- summary
  - use `std::string_view` or `std::array<char, N>` for safety and fixed content
  - avoid a modifiable `std::vector` when the set of vowels is constant

### Remove Vowels methods
- Method 1: remove while iterating
  - buggy because erasing characters while moving through the same string invalidates iterators and shifts the remaining data
  - time: worst-case O(n^2) if repeated erase is used
  - space: O(1) extra, but not recommended because it is unsafe and slow
- Method 2: build a new result string
  - append only non-vowel characters to a new `std::string`
  - time: O(n) with fixed vowel lookup; effectively linear with `m=10` vowel checks
  - space: O(n) for the output string, safe and clear
- Method 3: `std::remove_if` + `erase`
  - compact non-vowels first, then erase the removed suffix
  - time: O(n) overall
  - space: O(n) if making a copy first, otherwise O(1) extra when modifying in place
- Method 4: fixed boolean lookup table
  - use a compile-time `std::array<bool, 256>` and test `is_vowel[static_cast<unsigned char>(c)]`
  - time: O(n) with constant-time membership checks
  - space: O(1) extra for the lookup table

### Recommendation
- safest: build a new output string and skip vowels
- best fixed data: use `constexpr std::string_view` or `constexpr std::array<char, N>` for the vowel set
- fastest membership: use a compile-time boolean table for O(1) checks
- avoid erasing while iterating forward through the same container

## Miscellaneous

### Substring and stoi
- `std::string::substr(pos, len)` returns a new `std::string` from `pos` for `len` characters.
  - `instruction.substr(5)` returns the substring from index `5` to the end of `instruction`
  - `instruction.substr(0, 4)` returns the first four characters
- `std::stoi(s)` converts a numeric string `s` into an `int`
  - requires `#include <string>`
  - throws `std::invalid_argument` if `s` is not a valid integer string
  - throws `std::out_of_range` if the value is too large for `int`
- common pattern:
  - `int value = std::stoi(instruction.substr(5));`
  - extracts the substring starting at character 5, then parses it as an integer