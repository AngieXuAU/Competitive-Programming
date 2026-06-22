#include <iostream>
#include <string>

int main(){
    std::string s = "racecar";

    s.erase(s.size() / 2, 1);

    std::cout << "New s: " << s << std::endl;
} 