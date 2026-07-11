# Data Structures

## Key Concepts

- contiguous array
  - elements stored in one continuous block of memory
  - fast index access
  - good cache locality
  - insertion/removal in middle can be expensive
- sequence of blocks
  - elements stored in multiple smaller chunks
  - useful for efficient front/back operations
  - less compact than a single contiguous block
- container
  - object that stores data
  - examples: vector, deque, list, map
- constructor
  - special function used to create an object
  - can initialize from values, another object, or a range
- iterator
  - pointer-like object used to traverse a container
  - begin/end mark the range
  - dereference with `*it`

## Vector

- `std::vector<T>`
  - dynamic array
  - contiguous storage
  - `push_back()` adds at end
  - `size()` gives current length
  - `operator[]` supports index access
  - can grow and reallocate internally
  - good for random access

```cpp
std::vector<int> v = {1, 2, 3};
 v.push_back(4);
```

## Queue

- `std::queue<T>`
  - FIFO data structure
  - `push()` adds to back
  - `pop()` removes from front
  - `front()` reads front element
  - `empty()` checks whether queue is empty
  - not a standalone container; adaptor over another container
  - default underlying container: `std::deque`

```cpp
std::queue<int> q;
q.push(1);
q.push(2);
std::cout << q.front(); // 1
q.pop();
```

- converting from a vector
  - push elements one by one
  - example:

```cpp
std::vector<int> v = {1, 2, 3};
std::queue<int> q;
for (int x : v) q.push(x);
```

- `std::queue` does not take two iterators like `std::vector` does
  - `std::queue<int> q(v.begin(), v.end());` is not valid
