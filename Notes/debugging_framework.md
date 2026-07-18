# A Systematic Debugging Framework for DSA / CP

When you get stuck on a tricky implementation (like pointer manipulation, nested loops, or stateful traversals), trying to fix it by editing lines at random often introduces more bugs. Instead, use this structured debugging framework.

---

## Phase 1: Dry Run with a Minimal Tracing Table
Before writing or changing code, trace it line-by-line using a **Tracing Table**. Do not do this in your head—write it down.

1. **Pick a small, meaningful test case**:
   * For `backspace_string_compare`, choose something short but representative, like:
     * `s = "ab#c"`, `t = "ad#c"`
     * `s = "a#b"`, `t = "b"`
2. **List all state variables as columns**:
   * For this problem: `sptr`, `tptr`, `s_counter`, `t_counter`, `x`, `y`.
3. **Trace line-by-line**:
   * Write down the values of the variables at the start of each iteration or inner loop step.
   * *Example trap discovered this way*: "Wait, `sptr` becomes `-1`, but on the next line I do `x = s[sptr]`. That's an out-of-bounds read!"

---

## Phase 2: Add Strategic Print Debugging (Telemetry)
When your dry run reveals a discrepancy, or you want to see exactly what the computer is doing, inject temporary print statements. 

* **Rule of thumb**: Print the **state variables** at the entry and exit of every major control block (loops, `if/else`).
* **Format clearly**: Use labels and indentation so the output is easy to read.

### Example for Backspace String Compare:
```cpp
while (sptr >= 0 || tptr >= 0) {
    std::cout << "[LOOP START] sptr=" << sptr << ", tptr=" << tptr 
              << ", s_counter=" << s_counter << ", t_counter=" << t_counter << "\n";
    
    // ... skipping logic ...
    
    std::cout << "[AFTER SKIP] sptr=" << sptr << " (char='" << (sptr >= 0 ? s[sptr] : 'N') << "'), "
              << "tptr=" << tptr << " (char='" << (tptr >= 0 ? t[tptr] : 'N') << "')\n";
}
```

---

## Phase 3: The CP Pitfall Checklist
Run through these common implementation errors:

* **Boundary Violations (Out-of-Bounds)**:
  * Are you accessing `arr[index]` or `str[index]` when `index < 0` or `index >= size`?
  * *Tip*: In C++, `str[index]` on out-of-bounds is undefined behavior (often silent or crashes), whereas `str.at(index)` throws `std::out_of_range`. Use `.at()` while debugging to catch these instantly.
* **Infinite Loops**:
  * Does every branch in your `while` loop guarantee that the loop condition moves closer to terminating?
  * If you decrement a pointer (`sptr--`), did you also update the character variable (`x = s[sptr]`) that the loop condition depends on?
* **Loop Termination Conditions**:
  * If the loop is `while (sptr >= 0 && tptr >= 0)`, what happens if one string is completely processed (`sptr < 0`) but the other still has characters (`tptr >= 0`)? Should the program stop comparing, or should it recognize that they aren't equal?

---

## Phase 4: Simplify and Refactor
If the code has too many nested loops, nested `if-else` branches, and duplicate logic, it is very hard to debug. **Extract helper functions** or **simplify the state representation**.

For example, in `backspace_string_compare`:
* Instead of inline nested loops, could we write a helper function `int get_next_valid_index(const std::string &str, int index)`?
* This keeps the main function clean:
  ```cpp
  int i = s.size() - 1;
  int j = t.size() - 1;
  while (i >= 0 || j >= 0) {
      i = get_next_valid_index(s, i);
      j = get_next_valid_index(t, j);
      // Now compare s[i] and t[j] safely!
  }
  ```
