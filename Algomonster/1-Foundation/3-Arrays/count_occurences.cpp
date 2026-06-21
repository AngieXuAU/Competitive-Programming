#include <iostream>
#include <vector>
#include <cassert>

int count_targets(std::vector<int> vals, int target){
    int count = 0;

    for (int val: vals){
        if (val == target){
            count ++;
        }
    }

    return count;
}

int main(){
    assert(count_targets({1, 2, 3, 2, 4, 2}, 2) == 3);
    assert(count_targets({5, 5, 5, 5}, 5) == 4);
    assert(count_targets({1, 2, 3}, 7) == 0);

    std::cout << "All tests pass!";
    
    return 0;
}