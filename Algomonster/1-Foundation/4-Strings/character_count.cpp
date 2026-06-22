#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>

int main(){

    // testing something
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    
    auto start = std::chrono::steady_clock::now();

    // array method
    int asciiFreq[128] = {0};
    
    std::string text = "this is a test string";

    for (char c: text){
        asciiFreq[c] ++;
    }

    std::cout << "Method 1 results:" << "\n";
    for (int i = 97; i <= 122; i++){
        if (asciiFreq[i] != 0){
            std::cout << char(i) << ": " << asciiFreq[i] << "\n";
        }
    }

    // unordered map method
    std::unordered_map<char, int> letterFreq;
    
    for (char c: text){
        if (c != ' '){
            letterFreq[c] ++ ;
        }
    }
    
    std::cout << "Method 2 results:" << "\n";
    for (const auto& pair: letterFreq){
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << elapsed.count() << "ms\n";
    
    return 0;
}