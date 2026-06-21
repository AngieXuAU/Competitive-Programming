#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string text = "Hello World";
    
    // substrings
    std::string sub = text.substr(3, 6);
    std::cout << sub << std::endl;

    // transform algorithm
    std::transform(text.begin(), text.end(), text.begin() + 2, ::toupper);
    std::cout << text << std::endl;

    // adding and searching
    text.append("World");
    std::cout << (text.find("World") != std::string::npos) << std::endl;        // true
    std::cout << (text.find("Worldd") != std::string::npos) << std::endl;        // false

    return 0;
}