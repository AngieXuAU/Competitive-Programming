
#include <iostream>
#include <string>
#include <stack>

bool is_palindrome(std::string s){
    // method 1: reverse the string
    // std::string new_s;
    // for (int i = s.size() - 1; i >= 0; i--){
    //     new_s.push_back(s[i]);
    // }
    // return new_s == s;

    // method 2: use a stack
    std::string str_copy = s;
    std::stack<char> str_stack;

    if (str_copy.size() % 2 == 1){
        str_copy.erase(str_copy.size() / 2, 1);
    }

    for (int i = 0; i < str_copy.size(); i++){
        if (i < str_copy.size() / 2){
            str_stack.push(str_copy[i]);
        } else {
            char last = str_stack.top();
            str_stack.pop();
            if (last != str_copy[i]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    std::cout << is_palindrome("racecar") << "\n";
    std::cout << is_palindrome("hello") << "\n";
    std::cout << is_palindrome("a") << "\n";
    return 0;
}