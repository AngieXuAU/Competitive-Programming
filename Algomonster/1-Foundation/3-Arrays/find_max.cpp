
#include <iostream>
#include <vector>

int get_max(std::vector<int> arr){
    int max = arr[0];

    for(int i = 0; i < arr.size(); i++){
        max = (arr[i] > max) ? arr[i]: max; 
    }

    return max;
}

int main(){
    std::vector<int> arr1 = {3, 1, 4, 1, 5};
    int maximum = get_max(arr1);
    
    std::cout << maximum;
    
    return 0;
}