
#include <iostream>
#include <vector>
#include <string>

std::vector<int> rotate_array(std::vector<int> original, int k){
    std::vector<int> rotated = {};
    k %= original.size();

    for (int i = original.size() - k; i < original.size(); i++){
        rotated.push_back(original[i]);
    }

    for (int j = 0; j < original.size() - k; j++){
        rotated.push_back(original[j]);
    }

    // rotated = {3, 6, 9, 6, 3};
    return rotated;
}

void pprint(std::vector<int> rotated){
    for (int x: rotated){
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}
int main(){
    pprint(rotate_array({1, 2, 3, 4, 5}, 2));
    pprint(rotate_array({1, 2, 3}, 4)); 
    pprint(rotate_array({1, 2, 3, 4}, 0));

    return 0;
}