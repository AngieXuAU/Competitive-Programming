#include <iostream>
#include <vector>

int main(){
    // // explore inserting in the middle:
    // std::vector<int> arr1 = {1, 3, 5, 7, 9};
    // auto numbers_begin = arr1.begin();

    // // what is numbers_begin?
    // std::cout << *numbers_begin << std::endl;       // output = 1
    
    // // view the vector
    // arr1.insert(numbers_begin + 2, 99);
    // for (int x: arr1){
    //     std::cout << x << "\t";                     // output = 1, 3, 99, 5, 7, 9
    // }

    // explore removing in the middle:
    std::vector<int> arr2 = {2, 4, 6, 8, 10};
    std::vector<int>::iterator beginning = arr2.begin() + 2;

    // what is inside beginning?
    std::cout << std::endl << "Insertion position: " << *beginning << std::endl;
    arr2.erase(beginning);

    // view the vector
    for (int y: arr2){
        std::cout << y << "\t";
    }
    
    return 0;
}