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
