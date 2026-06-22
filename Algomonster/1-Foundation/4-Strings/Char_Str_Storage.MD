# Character and String Storage in C++ 🖥️

A first-principles reference guide for low-level text manipulation.

---

## 1. The Primitive Layer: `char` 🔤
* **Hardware Reality**: Computers only store binary data. Letters are an illusion managed by lookup tables (like ASCII).
* **Memory Size**: Exactly 1 byte (8 bits).
* **Mechanism**: Storing `'a'` means writing the number `97` (`01100001` in binary) into a single memory slot.

---

## 2. Raw Character Arrays (C-Strings) 📜
* **Structure**: A continuous, sequential line of `char` bytes in memory.
* **The Null Terminator (`\0`)**: Because memory is a continuous sea of bytes, functions reading text need a stop sign. The null terminator is a byte containing all zeros (`00000000`).
* **Memory Footprint**: A string literal like `"trade"` takes up **6 bytes** of memory (5 for the letters + 1 for the `\0`).

---

## 3. Dynamic Management: `std::string` 🧵
* **Role**: A smart object wrapper around a raw character array that automates dynamic memory management on the heap.
* **Internal Trackers**:
  * **Size**: The number of valid characters currently in the string.
  * **Capacity**: The total number of bytes allocated in memory before a resize is required.
* **Growth Strategy**: When size exceeds capacity, it requests a new, larger block of memory (often doubling the size), copies the old characters, and frees the old memory.
* **Optimization**: Use `.reserve(n)` to pre-allocate memory at startup, completely eliminating runtime allocation latency.

---

## 4. Function Parameters & Memory Safety 🔒
* **Pass-by-Value (`void func(std::string s)`)**: Creates a complete copy of the text. Highly inefficient for large data; causes latency spikes.
* **Pass-by-Reference (`void func(std::string& s)`)**: Passes the memory address directly. Zero copy, fast, but risks accidental data corruption.
* **Const Reference (`void func(const std::string& s)`)** 🛡️: **The standard pattern.** Zero copy + compiler-enforced read-only safety. It also extends the lifetime of temporary strings (rvalues) passed into the function.

---

## 5. Lightweight Performance: `std::string_view` 👀
* **Structure**: A tiny 16-byte object containing just a **pointer** to the start of a string and its **length**.
* **Memory Action**: Zero allocation, zero copying. It is a read-only window looking at existing text.
* **Literal Storage**: Fixed literals (e.g., `"AAPL"`) are baked directly into the read-only section of the compiled binary file. 
* **`constexpr std::string_view`** ⚡: Evaluated at compile-time. Points directly to the binary's read-only memory with zero runtime overhead.
* **The Lifetime Trap** ⚠️: A `std::string_view` does not own the data. If the underlying string or network packet is deleted, the view becomes a **dangling pointer**, leading to garbage reads or crashes.

*For more information:*
[Gemini Conversation](https://gemini.google.com/app/c612f184294a5ca5)