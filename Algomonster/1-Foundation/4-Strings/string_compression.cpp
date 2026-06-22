
#include <iostream>
#include <string>

std::string compress_string(const std::string& s){
    std::string compressed = "";
    int temp_count = 1;
    char prev = s[0];

    for (int i = 1; i < s.size(); i++){
        char c = s[i];
        if (c == prev){      // if same letter as previous
            temp_count ++;          // add one to count
            continue;

        } else {                     // if different letter
            compressed.append(1, prev);
            // if (temp_count > 0){
            // }
            
            compressed.append(1, char(temp_count+48));
            prev = c;
            temp_count = 1;
            
            // std::cout << compressed << std::endl;
        }
    }
    compressed.append(1, prev).append(1, char(temp_count+48));
    return compressed;
}

int main(){
    std::cout << compress_string("aaabbc") << "\n";
    std::cout << compress_string("aabbccdd") << "\n";
    std::cout << compress_string("abc") << "\n";
    return 0;
}