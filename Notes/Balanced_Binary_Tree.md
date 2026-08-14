# Binary Tree

## Relations between structural types

We can categorize these tree types into two main categories:
1. **Structural Properties** (How the tree is shaped: *where* nodes are placed and how many children they have).
2. **Ordering Properties** (What values are *stored inside* the nodes).

---

### 1. Structural Hierarchy (Shape & Geometry)

The 4 structural types—**Full**, **Complete**, **Balanced**, and **Perfect**—are related like geometric shapes (e.g., how every square is a rectangle, but not every rectangle is a square).

Here is how they fit into one another:

#### 🏆 **Perfect Binary Tree** (The ultimate symmetric tree)
- **Definition**: Every internal node has exactly 2 children, and **all leaf nodes are at the exact same level**.
- **Special Case Relationships**: A Perfect tree is a strict special case of **all three**:
  - It is a **Complete** tree (all levels are 100% full).
  - It is a **Full** tree (every node has 0 or 2 children).
  - It is a **Balanced** tree (height difference between subtrees is always 0 everywhere).

#### 📦 **Complete Binary Tree**
- **Definition**: Every level is completely filled, except possibly the last level, which must be filled **from left to right**.
- **Special Case Relationship**:
  - **Every Complete tree is automatically a Balanced tree!** (Filling left-to-right guarantees the left and right subtrees never differ in height by more than 1).
  - *Note*: Not every Complete tree is Full (the last level might leave a node with only 1 child).

#### 🌿 **Full Binary Tree**
- **Definition**: Every node has **either 0 or 2 children** (never 1 child).
- **Special Case Relationship**:
  - Full and Complete are independent concepts—a tree can be Full without being Complete, or Complete without being Full!
  - But if a tree is **both Full AND Complete** (with all leaves at the same depth), it becomes **Perfect**.

#### ⚖️ **Balanced Binary Tree**
- **Broadest category**: Includes Perfect trees, Complete trees, and many other shapes!

> **Subtree Height**: The maximum number of nodes on the path from the subtree's root down to its deepest leaf. An empty subtree (`null`) has a height of `0`.

A binary tree is **height-balanced** if, **for *every* single node in the tree**, the absolute difference between the height of its left subtree and the height of its right subtree is **at most 1**:
$$\lvert \text{height}(\text{left}) - \text{height}(\text{right}) \rvert \le 1$$

---

### Example 1: A Balanced Binary Tree

Consider this binary tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

Let's calculate the height of left and right subtrees for **every** node from the bottom up:

1. **Leaf Nodes (4, 5, 3)**:
   - They have no children (left = `null`, right = `null`), so left height = `0`, right height = `0`.
   - Difference = $|0 - 0| = 0 \le 1$ ✅
   - **Height of node 4, 5, 3** = `1`

2. **Node 2**:
   - Left child is `4` (height = `1`)
   - Right child is `5` (height = `1`)
   - Difference = $|1 - 1| = 0 \le 1$ ✅
   - **Height of node 2** = $1 + \max(1, 1) = 2$

3. **Root Node (1)**:
   - Left subtree is rooted at `2` (height = `2`)
   - Right subtree is rooted at `3` (height = `1`)
   - Difference = $|2 - 1| = 1 \le 1$ ✅
   - **Height of node 1** = $1 + \max(2, 1) = 3$

Since **every single node** (1, 2, 3, 4, 5) satisfies the condition ($\le 1$), this tree is **BALANCED**.

---

### Example 2: An Unbalanced Binary Tree

Now look at this tree:

```text
        1
       / \
      2   3
     /
    4
   /
  5
```

Let's check the heights:

1. **Node 5**: Leaf node $\implies$ height = `1`.
2. **Node 4**: Left height = `1` (node 5), Right height = `0` (`null`). Difference = $|1 - 0| = 1 \le 1$ ✅ $\implies$ height = `2`.
3. **Node 2**:
   - Left subtree (rooted at `4`) height = `2`
   - Right subtree (`null`) height = `0`
   - Difference = $|2 - 0| = 2 > 1$ ❌ **(FAILS at Node 2!)**
4. **Root Node (1)**:
   - Left subtree (rooted at `2`) height = `3`
   - Right subtree (rooted at `3`) height = `1`
   - Difference = $|3 - 1| = 2 > 1$ ❌ **(FAILS at Node 1!)**

Even if only one node in the tree fails the condition, the **entire tree is NOT balanced**.

---

### Socratic Check

To make sure this clicks:

Suppose we take **Example 1** above and add a single new child `6` underneath node `4`:

```text
        1
       / \
      2   3
     / \
    4   5
   /
  6
```

**Question for you:**
1. What is the height of node `2` now?
2. Is this modified tree still balanced? Why or why not?

---

### Visual Hierarchy

$$\text{Perfect} \subset \text{Complete} \subset \text{Balanced}$$
$$\text{Perfect} \subset \text{Full}$$

---

### 2. What about a Binary Search Tree (BST)?

A **Binary Search Tree (BST)** belongs to the **Ordering Category**, not the Structural Category.

- **Rule**: For every node, all values in its left subtree are smaller ($<$), and all values in its right subtree are larger ($>$).
- **Relationship to the others**: **BST is orthogonal (independent) to structure.** 
  - A BST can be Balanced, Complete, Full, Perfect, or even a completely unbalanced straight line (like a linked list)!

---

### Socratic Check

To test your mental map of these relationships, answer these true/false questions:

1. **True or False?** "Every Perfect Binary Tree is a Complete Binary Tree."
2. **True or False?** "Every Balanced Binary Tree is a Complete Binary Tree."
3. **True or False?** "A Binary Search Tree (BST) MUST be balanced."

## Tree Traversal
