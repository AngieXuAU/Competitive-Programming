#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> remove_element(std::vector<int> arr, int target){
    // // really bad to edit something that you are looping through
    // for (int i = 0; i < arr.size() ; i++){
    //     if (arr[i] == target){
    //         arr.erase(arr.begin() + i);
    //     }
    // }
    std::vector<int> arr2;

    for (int val: arr){
        if (val != target){
            arr2.push_back(val);
        }
    }
    return arr2;
}

int main(){
    std::vector<int> result = remove_element({1, 2, 3, 2, 4, 2}, 2);

    for (int val: result){
        std::cout << val << "\t";
    }
    return 0;
}