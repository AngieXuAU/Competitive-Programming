#include <iostream>
#include <string>
#include <cassert>

int compare_strings(std::string s1, std::string s2){
    if (s1 == s2){
        return 0;
    } else {
        return s1 < s2 ? -1 : 1;
    }
}

int main(){
    assert(compare_strings("hello", "hello") == 0);    
    assert(compare_strings("apple", "orange") == 1);    
    assert(compare_strings("cherry", "banana") == -1);
    std::cout << "All tests pass" <<std::endl;
    return 0;
}