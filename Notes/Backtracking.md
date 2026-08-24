# Backtracking

DFS on a tree that you have to build as you go.

# Tree Comparison
- Branches = choices
- Leaves = complete answers

# How to Think
Since this is a DFS, recursion can be used.
1. When do I have a complete answer? Use this to generate a base case.
2. What choices can I make from here?

## Example:
Given n, return all possible strings of length n containing only A or B.

```py
def bt_dfs(path):
    if len(path) == n:
        result.append("".join(path))
        return
    
    for char in ["A", "B"]:
        path.append(char)
        bt_dfs(path)
        path.pop()
```