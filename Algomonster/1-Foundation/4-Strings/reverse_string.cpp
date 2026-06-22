#include <iostream>
#include <string>
#include <algorithm>

std::string reverse_str(const std::string& s){
    // method 1: constructing a string backwards
    std::string rev(s.rbegin(), s.rend());

    // method 2: std::reverse
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    return rev;
}

int main(){
    std::cout << reverse_str("hello") << "\n";
    std::cout << reverse_str("AlgoMonster") << "\n";
    std::cout << reverse_str("a") << std::endl;
    return 0;
}