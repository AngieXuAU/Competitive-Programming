
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string remove_vowels(const std::string& s){
    std::vector <char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};         // any way to optimise this knowing the vowels vec has to be fixed?
    
    // // method 1: iterate through s and remove if in vowels
    // for (char c: s){
    //     auto it = std::find(vowels.begin(), vowels.end(), c);
    //     if (it != vowels.end()){
    //         // problem: looping while modifying (red flag)
    //     }
    // }
    
    // method 2: construct a new string if not in vowels
    std::string no_vowels;
    for (char c: s){
        auto it = std::find(vowels.begin(), vowels.end(), c);
        if (it == vowels.end()){
            no_vowels.push_back(c);
        }
    }
    return no_vowels;
}

int main(){
    std::cout << remove_vowels("hello world") << "\n";
    std::cout << remove_vowels("AlgoMonstEr") << "\n";
    std::cout << remove_vowels("aeiOu") << "\n";
    return 0;
}