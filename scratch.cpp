#include <iostream>
#include <string>

int main(){
    char letter = 'a';
    int number = 10;
    int* ptr = &number;

    std::cout << ptr << "\t" << *ptr << std::endl;

} 