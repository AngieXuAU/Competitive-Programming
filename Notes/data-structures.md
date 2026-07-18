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

## Linked Lists

- **Basic Node Structure**: A node consists of a value (`val`) and a pointer to the next node (`next`).
  - Accessing elements requires traversing from the `head` node ($O(N)$ time).

### Adding to Tail: Time Complexity Comparison

#### 1. Without a Tail Pointer ($O(N)$ Time)
If you only keep track of the `head` pointer, appending a node requires traversing the entire list to locate the current tail node.
- **Complexity**: $O(N)$ time, $O(1)$ space.

```cpp
Node<int>* insert_at_tail(Node<int>* head, int value) {
    Node<int>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new Node<int>{value};
    return head;
}
```

#### 2. With a Tail Pointer ($O(1)$ Time)
Maintaining a pointer directly to the last node (the `tail`) allows appending a new node in constant time.
- **Complexity**: $O(1)$ time, $O(1)$ space.

### Designing the Tail Pointer (Best Practices)

- **Incorrect/Unconventional Approach (Inside every `Node`)**: Storing `Node* tail` inside every node requires updating all nodes' `tail` pointers whenever a new element is appended, degrading the operation back to $O(N)$ time complexity.
- **Asymmetric Approach (Only in the `head` Node)**: Storing the `tail` pointer only in the `head` node makes the head special and creates overhead if the head pointer changes (e.g., prepending or deleting the head).
- **Conventional Approach (Wrapper Struct)**: Use a separate struct/class (e.g., `LinkedList`) to manage list-level metadata (`head` and `tail`) separately from node-level data.

```cpp
template <typename T> struct Node {
    T val;
    Node<T>* next;
    explicit Node(T val, Node<T>* next = nullptr) : val{val}, next{next} {}
};

template <typename T> struct LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};
```

### Memory Management & Destructors

#### Recursive Destructor Pitfall
It is common to see `Node` defined with a recursive destructor to clean up memory:
```cpp
~Node() {
    delete next; // Recursively deletes the rest of the list
}
```
- **Risk**: For long lists (e.g., $10^5$ elements), the recursive call chain creates $O(N)$ stack frames, causing a **Stack Overflow** (segmentation fault) due to call stack exhaustion.

#### Best Practice: Iterative Cleanup
Avoid recursive node destruction. Instead, handle cleanup iteratively within the wrapper structure's destructor to guarantee $O(1)$ auxiliary stack space:
```cpp
template <typename T> struct LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next_node = current->next;
            delete current;
            current = next_node;
        }
    }
};
```

### Avoiding Use-After-Free on Node Deletion

When deleting a node from a linked list, you must capture the next node's address **before** freeing/deleting the node.

#### The Bug (Use-After-Free)
If you delete a pointer first, any subsequent attempt to access its members (like `current->next`) uses deallocated memory, leading to undefined behavior or segmentation faults.
```cpp
// ❌ INCORRECT (Dangling Pointer / Use-After-Free)
delete head;
return head->next; // CRASH! head has already been deallocated
```

#### The Safe Fix (Capture first)
```cpp
//  CORRECT
Node<int>* new_head = head->next; // 1. Save pointer to next node
delete head;                       // 2. Safely free current head memory
return new_head;                   // 3. Return the saved pointer
```


