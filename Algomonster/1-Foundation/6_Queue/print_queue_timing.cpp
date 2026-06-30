
#include <iostream>
#include <vector>

std::vector<int> simulate_print_queue(std::vector<int>& jobs) {
    // WRITE YOUR BRILLIANT CODE HERE
    int cumulative = 0;
    std::vector<int> timestamps;

    for (int job: jobs){
        cumulative += job;
        timestamps.push_back(cumulative);
    }
    return timestamps;
}

int main(){
    std::vector<int> jobs = {5, 3, 8, 2};
    std::vector<int> result = simulate_print_queue(jobs);
    
    for (int item: result){
        std::cout << item << "\t";
    }

    return 0;
}