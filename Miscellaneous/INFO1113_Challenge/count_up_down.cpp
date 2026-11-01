// finds the first occurrence of 123 and replaces it with 321
// returns the modified string not containing 123

#include <iostream>
#include <string>

using namespace std;

// returns the index of the 1 in the first 123 found
// x provides the first possible value this could be
// ie. everything before has no 123 for sure
int find(const string &text, int i = 0) {
    int j = i;

    char anchor = text[i];
    while (i < text.size() - 2) {
        j = i;
        anchor = text[i];
        if (anchor == '1') {
            j++;
            if (text[j] == '2') {
                char tail = text[j + 1];
                if (tail == '1') {
                    i = j + 1;
                    continue;
                } else if (tail == '3') {
                    return i;
                } else {
                    i = j + 2;
                    continue;
                }
            } else if (text[j] == '3') {
                i += 2;
                continue;
            } else {
                i++;
                continue;
            }
        } else {
            i++;
            continue;
        }
    }

    // string tmp;
    // while (i < text.size() - 2) {
    //     if (text[i] != '1') {
    //         i++;
    //     } else {
    //         if (text[i + 1] != '2') {
    //             i++;
    //         } else {
    //             if (text[i + 2] != '3') {
    //                 i++;
    //             } else {
    //                 return i;
    //             }
    //         }
    //     }
    // }

    return -1;
}

string transform(string &text, int x = 0) {
    int i = find(text, x);
    if (i == -1) {
        return text;
    }

    // overwrite
    text[i] = '3';
    text[i + 1] = '2';
    text[i + 2] = '1';

    return transform(text, i + 2);

    // if find = -1, return text
    // else return transform(text, find(text))
}

int main() {
    string starting = "1112323";
    string result = transform(starting);

    cout << result << "\n";
    return 0;
}

// ============================================================================
// SUGGESTED SOLUTIONS
// ============================================================================

// ----------------------------------------------------------------------------
// 1. Clean Direct Window (Recommended for simplicity & branch prediction)
// ----------------------------------------------------------------------------
// Why it's fast: C++ short-circuit evaluation (`&&`) acts as a natural filter.
// text[i] == '1' fails ~66% of the time, so the CPU rarely checks pos 2 or 3.
// Modern compilers unroll this cleanly with minimal branch misprediction overhead.
int find_clean(const string &text, size_t pos = 0) {
    if (text.size() < 3) return -1;
    for (size_t i = pos; i + 2 < text.size(); ++i) {
        if (text[i] == '1' && text[i + 1] == '2' && text[i + 2] == '3') {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// ----------------------------------------------------------------------------
// 2. Boyer-Moore-Horspool Skip Search (Formalization of your skip intuition)
// ----------------------------------------------------------------------------
// Instead of inspecting from left-to-right, inspect the tail: text[i + 2].
// - If tail == '3': possible match! Verify text[i+1]=='2' and text[i]=='1'.
//   If not a match, '3' cannot be at pos 0 or 1, so jump ahead by 3!
// - If tail == '1': '1' can only be at pos 0 of "123", so jump ahead by 2.
// - If tail == '2': '2' can only be at pos 1 of "123", so jump ahead by 1.
int find_horspool(const string &text, size_t pos = 0) {
    if (text.size() < 3) return -1;
    size_t i = pos;
    while (i + 2 < text.size()) {
        char tail = text[i + 2];
        if (tail == '3') {
            if (text[i + 1] == '2' && text[i] == '1') {
                return static_cast<int>(i);
            }
            i += 3; // '3' cannot appear in "12", skip full window
        } else if (tail == '1') {
            i += 2; // '1' can only align with pattern[0]
        } else {
            i += 1; // '2' can only align with pattern[1]
        }
    }
    return -1;
}

// ----------------------------------------------------------------------------
// 3. Deterministic Finite Automaton (DFA / KMP / Streaming)
// ----------------------------------------------------------------------------
// Reads each character exactly once in a single pass without lookaheads (i+1)
// or indexing bounds risks. Ideal for streaming data (cin / sockets).
int find_dfa(const string &text, size_t pos = 0) {
    int state = 0; // 0 = "", 1 = "1", 2 = "12"
    for (size_t i = pos; i < text.size(); ++i) {
        char c = text[i];
        if (c == '1') {
            state = 1; // any '1' resets/continues prefix to "1"
        } else if (c == '2') {
            state = (state == 1) ? 2 : 0;
        } else if (c == '3') {
            if (state == 2) return static_cast<int>(i - 2);
            state = 0;
        } else {
            state = 0;
        }
    }
    return -1;
}

// ----------------------------------------------------------------------------
// 4. Idiomatic C++ Standard Library (SIMD accelerated)
// ----------------------------------------------------------------------------
// In libstdc++ / libc++, std::string::find uses vectorized instructions
// (SSE2 / AVX2 memchr) scanning 16 to 32 bytes per cycle.
int find_std(const string &text, size_t pos = 0) {
    size_t idx = text.find("123", pos);
    return idx == string::npos ? -1 : static_cast<int>(idx);
}