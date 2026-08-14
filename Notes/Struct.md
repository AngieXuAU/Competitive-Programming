# C++ Structs & Memory Management

## Overview
In C++, a `struct` is fundamentally a class where members are `public` by default. Used heavily in CP/DSA for tree/graph nodes and custom data structures.

---

## Active Recall 🧠

Qs:
1. What does `explicit` prevent on a single-argument struct constructor?
2. What order of tree traversal does a recursive destructor like `~Node() { delete left; delete right; }` perform?
3. What happens in C++ if you execute `delete ptr;` when `ptr` is `nullptr`?
4. What is the risk of recursive destructors in trees with high depth ($N = 10^5$)?

--

As:
1. Prevents implicit type conversion (e.g. `Node<int> n = 5;`), requiring explicit instantiation (`Node<int> n(5);`).
2. Post-Order Traversal (Left subtree $\rightarrow$ Right subtree $\rightarrow$ Current Node).
3. It safely does nothing (no-op).
4. Deep recursion stacks causing stack overflow on skewed trees of depth $\mathcal{O}(N)$.

---

## 1. Generic Templated Structs
Allows reusing node structure across different data types (`int`, `string`, `double`).

```cpp
template <typename T> 
struct Node {
    T val;
    Node<T> *left;
    Node<T> *right;

    // Constructor with default nullptr children
    explicit Node(T val, Node<T> *left = nullptr, Node<T> *right = nullptr)
        : val{val}, left{left}, right{right} {}

    // Recursive Destructor
    ~Node() {
        delete left;
        delete right;
    }
};
```

---

## 2. Constructor & `explicit` Keyword
- **Implicit Conversion Prevention:** Adding `explicit` before a constructor stops C++ from silently converting raw values into `Node` objects.
  - ❌ `Node<int> n = 5;` (Fails to compile when constructor is `explicit`)
  -  `Node<int> n(5);` or `Node<int> n{5};` (Explicit instantiation required)
- **Why it matters:** Prevents performance overhead and subtle bugs caused by temporary objects instantiated implicitly behind the scenes.

---

## 3. Destructors (`~Node()`) & Recursive Cleanup
- **Trigger:** Automatically invoked when a `struct`/object goes out of scope or is explicitly targeted by `delete ptr;`.
- **Post-Order Recursive Deletion:**
  - `delete left;` recursively calls `~Node()` on the left child before deleting the current node.
  - Traversal order: Left Subtree $\rightarrow$ Right Subtree $\rightarrow$ Current Node (Post-Order).
- **Safety with `nullptr`:**
  - In C++, `delete nullptr;` is a safe **no-op** (does nothing and returns). No crash occurs when deleting null child pointers on leaf nodes.
- **CP Pitfall:**
  - **Stack Overflow Risk:** Deeply skewed trees (depth $N \approx 10^5$) cause linear recursive call stacks ($\mathcal{O}(N)$ depth), which can trigger stack overflow during deletion.
