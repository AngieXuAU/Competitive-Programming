# Notes

## Implicit Type Conversion in C++

C++ can automatically convert compatible numeric values from one type to another. This is called implicit type conversion or coercion.

### Why the code works

- `append_and_count(arr, vals)` returns an `int`.
- Assigning that result to `float size` does not change the function return type.
- The compiler converts the integer value `5` to `5.0` before storing it in `size`.

### Allowed conversions

- `int` -> `float` or `double` (safe promotion)
- `char` / `short` -> `int` or `float`
- `float` -> `double`
- `int` -> `long`, `long long`, `double`

These are allowed because they move from a smaller or less precise type to a larger or more precise type.

### Narrowing conversions

- `float` -> `int`
- `double` -> `int`
- `double` -> `float` when precision may be lost

These can trigger warnings or be rejected under stricter initialization rules.

### Brace initialization

- `float size{ append_and_count(arr, vals) };` still works for this case because `int` to `float` is not narrowing here.
- Brace initialization is useful because it forbids true narrowing conversions, such as `int x{5.5};` or `int x{someFloat};` when data would be truncated.

### String and character conversion

- `std::string s{c};` is valid when `c` is a `char`; `std::string` can construct a one-character string from it.
- `std::string s = "hello";` constructs from a C-string literal (`const char*`).
- `std::string` can also be created from a temporary `std::string` or any compatible string-like constructor.

### Casts and conversions

- implicit conversion: the compiler converts compatible types automatically, e.g. `int` → `float`, `char` → `int`, `float` → `double`.
- explicit conversion / cast: tell the compiler to convert, e.g. `static_cast<int>(x)`.
- `static_cast<T>(value)` is the normal explicit cast for safe conversions.
- `const_cast<T>(value)` removes const/volatile qualifiers.
- `reinterpret_cast<T>(value)` is for low-level pointer or bit reinterpretation.
- `dynamic_cast<T>(value)` is for safe downcasting within polymorphic class hierarchies.

### Key point

The compiler accepts `float size = append_and_count(arr, vals);` because the integer result is safely converted to a floating-point value, not because the types are identical.

## What is an iterator?

- An iterator is a position marker for a container like `std::vector`.
- It points to one element and can move to the next or previous element.
- It is not an `int`; it is a special object used by container operations like `insert` and `erase`.

Example:
- `auto it = arr1.begin() + 2;` stores the iterator position.
- `arr1.insert(it, 99);` inserts at that position.

## Quick testing in C++

### 1) Using `assert`

A minimal approach similar to Python's `assert` checks. Fails fast and prints file/line.

```cpp
#include <cassert>
#include <vector>

int get_max(const std::vector<int>& a); // your function

int main(){
	assert(get_max({3,1,4,1,5}) == 5);
	assert(get_max({7}) == 7);
	std::cout << "All tests passed\n";
	return 0;
}
```

Notes: `assert` aborts on failure and can be disabled with `-DNDEBUG`.

### 2) Small test harness (recommended)

Provides clear pass/fail messages and exits non-zero on failure (useful for CI).

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>

int get_max(const std::vector<int>& a); // your function

void expect_equal(int expected, int actual, const char* name){
	if (expected != actual){
		std::cerr << "FAIL: " << name << " — expected " << expected << ", got " << actual << '\n';
		std::exit(1);
	} else {
		std::cout << "PASS: " << name << '\n';
	}
}

int main(){
	expect_equal(5, get_max({3,1,4,1,5}), "basic");
	expect_equal(7, get_max({7}), "single element");
	std::cout << "All tests passed\n";
	return 0;
}
```

How to run (folder with `find_max.cpp`):

```bash
g++ -std=c++17 find_max.cpp -o find_max.exe
.\find_max.exe
```

Both approaches let you keep tests inside the same file (`find_max.cpp`) for convenience.

## `std::string::npos` and `find()`

- `npos` = "no position", special constant returned when search fails.
- `string.find(char)` or `string.find(substring)` returns the index of first match, or `npos` if not found.

Always check `!= npos` before using the index:

```cpp
std::string s = "hello world";
size_t pos = s.find('o');
if (pos != std::string::npos) {
    std::cout << "Found at " << pos << '\n';  // 4
}
```

Pattern: returns both the success status and the position in one value.

## Built-in Algorithms

### String

- `std::transform(first, last, d_first, op)` applies `op` to each element in `[first, last)` and writes the results starting at `d_first`.
- If `d_first` points into the same container as the input range, the transform can overwrite elements that have not yet been read.
- Example: `std::transform(text.begin(), text.end(), text.begin() + 2, ::toupper);` reads from `text` and writes back shifted by 2, so later steps may use already-transformed characters.

## Optimisation and Memory

- `result.reserve(5000);` reserves space for 5000 characters.
- If you append beyond that, `std::string` will grow and may reallocate; it does not stop you from adding.

