Viewed find_all_anagrams.cpp:24-57

Excellent breakdown! You nailed the complexities and edge-case handling.

Here is a quick refinement on **Question 3** regarding the sorting alternative:

* Let $N$ be `original.length()` and $K$ be `check.length()`.
* **Sorting target once**: `std::sort(check)` takes $\mathcal{O}(K \log K)$.
* **At each of the $(N - K + 1)$ windows**: 
  1. Copy substring of length $K$: $\mathcal{O}(K)$.
  2. Sort substring of length $K$: $\mathcal{O}(K \log K)$.
  3. Compare two sorted strings of length $K$: $\mathcal{O}(K)$.
* **Total Time Complexity**: $\mathcal{O}(N \cdot K \log K)$, which simplifies to $\mathcal{O}(N \cdot K \log K)$ overall.
* **Space Complexity**: $\mathcal{O}(K)$ for the extracted substring copy.

Compared to your optimal $\mathcal{O}(N)$ sliding window solution with $\mathcal{O}(1)$ space, the sorting approach would be significantly slower and waste memory allocations!

---

### Summary of Work Done
* **Diagnosed Cognitive Errors**: Pinpointed state-reset, asymmetric enter/exit updates, and target vs. deficit check misconceptions.
* **Refactored Code**: Achieved clean $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ space implementation of `find_all_anagrams`.
* **Logged Insights**: Appended detailed entry into [log.md](file:///c:/Users/angel/Repositories/Competitive-Programming/Optimisations/log.md).

Viewed notes.md:27-53

Great observation! Breaking down Big-O expressions and simplifying them is a crucial skill in competitive programming and interview settings. 

Here is the exact step-by-step thinking process of how we take a verbose, multi-step complexity breakdown and reduce it to its canonical Big-O form:

---

### Step 1: Write down every piece explicitly
First, identify all variables and count the operations per step:
* Let $N = \text{length of } \texttt{original}$
* Let $K = \text{length of } \texttt{check}$
* **Number of windows**: The window of size $K$ slides from index $0$ to $N - K$. That means there are $(N - K + 1)$ total window positions.
* **Cost per window**:
  1. Extract substring of length $K$: $\mathcal{O}(K)$ time
  2. Sort substring of length $K$: $\mathcal{O}(K \log K)$ time
  3. Compare two strings of length $K$: $\mathcal{O}(K)$ time

Putting all operations together:
$$\text{Total Time} = \underbrace{K \log K}_{\text{Initial sort of check}} + \sum_{\text{each window}} \left( \underbrace{K}_{\text{copy}} + \underbrace{K \log K}_{\text{sort}} + \underbrace{K}_{\text{compare}} \right)$$

---

### Step 2: Combine terms inside the loop
Inside each window step, sum the costs:
$$\text{Cost per window} = K + K \log K + K = 2K + K \log K$$

Since there are $(N - K + 1)$ windows, multiply the cost per window by the number of windows:
$$\text{Total Time} = K \log K + (N - K + 1) \cdot (2K + K \log K)$$

---

### Step 3: Apply the Rules of Asymptotic Notation (Big-O Simplification)

In Big-O analysis, we apply **three simplification rules**:

#### Rule 1: Drop Low-Order Additive Terms inside parentheses
When comparing $K \log K$ vs. $2K$, as $K$ grows large, $K \log K$ strictly dominates $2K$. 
So $(2K + K \log K)$ becomes $\mathcal{O}(K \log K)$.

#### Rule 2: Simplify the Window Count
In competitive programming constraints, usually $N \gg K$ (e.g., $N = 10^5, K = 3$). 
Therefore, $(N - K + 1)$ is dominated by $N$, which we treat as $\mathcal{O}(N)$ window iterations.

#### Rule 3: Multiply and drop non-dominant constants
Multiplying $N$ window iterations by $K \log K$ work per window gives:
$$\mathcal{O}(N \cdot K \log K)$$

Notice how the initial $\mathcal{O}(K \log K)$ sort of `check` at the start is also dropped because $N \cdot K \log K > K \log K$.

---

### Summary Checklist for Big-O Simplification

Whenever you face a multi-term expression:
1. **Identify dominant terms**: In $A + B$, if $A$ grows much faster than $B$, drop $B$.
2. **Ignore constant factors**: $2K \log K \rightarrow K \log K$.
3. **Product Rule**: $\text{(Number of Iterations)} \times \text{(Dominant Cost per Iteration)}$.