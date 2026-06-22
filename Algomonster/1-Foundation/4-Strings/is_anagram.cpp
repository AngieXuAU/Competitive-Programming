#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

bool is_anagram(const std::string& s, const std::string& t){
    if (s.size() != t.size()) {
        return false;
    }
    
    // // method 1: alphabetise them both and compare
    // std::vector<char> s_vec;
    // for (char c: s){
    //     s_vec.push_back(c);
    // }
    // std::sort(s_vec.begin(), s_vec.end());

    // std::vector<char> t_vec;
    // for (char c: t){
    //     t_vec.push_back(c);
    // }
    // std::sort(t_vec.begin(), t_vec.end());

    // return (s_vec == t_vec);

    // // method 2: iterate through one and remove letters to check for a match
    // std::vector<char> ref_vec;
    // for (char c: s){
    //     ref_vec.push_back(c);
    // }

    // for (char target: t){
    //     if (ref_vec.size() == 0){               // if the first word has run out of letters for the second word to compare w/
    //         return false;
    //     }
    //     auto it = std::find(ref_vec.begin(), ref_vec.end(), target);        // find the target letter
    //     if (it != ref_vec.end()){               // if found
    //         ref_vec.erase(it);                  // erase it
    //     }
    // }

    // if (ref_vec.size() == 0){
    //     return true;
    // }
    // return false;

    // method 3: counting method
    std::array<int, 26> count{};
    for (char a: s){
        count[int(a)-97] ++;
    }
    for (char b: t){
        count[int(b)-97] --;
    }

    for (int c: count){
        if (c != 0) {
            return false;
        }
    }
    return true;
}

int main(){
    std::cout << is_anagram("listen", "silent") << "\n";        // expected: 1
    std::cout << is_anagram("hello", "world") << "\n";        // expected: 0
    std::cout << is_anagram("rat", "car") << "\n";           // expected: 0
    std::cout << is_anagram("triangle", "integral") << "\n"; // expected: 1
    std::cout << is_anagram("apple", "papel") << "\n";       // expected: 1
    std::cout << is_anagram("abc", "ab") << "\n";           // expected: 0
    std::cout << is_anagram("aabbcc", "abcabc") << "\n";   // expected: 1
    return 0;
}