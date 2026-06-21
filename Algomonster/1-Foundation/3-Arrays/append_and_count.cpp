#include <iostream>
#include <vector>

int append_and_count(std::vector<int>& arr, std::vector<int>& values){
    for (int val: values){
        arr.push_back(val);
    }

    return arr.size();

}

int main(){
    std::vector<int> arr = {10, 20};
    std::vector<int> vals = {30, 40, 50};

    int size = append_and_count(arr, vals);

    std::cout << size;

    return 0;
}