
#include <iostream>
#include <vector>

int time_required_to_buy(std::vector<int>& tickets, int k) {
    int timer = 0;
    int index;
    while (tickets[k] > 0){
        timer ++;
        index = timer % tickets.size();
    }
    for (int counter = 0; ; counter ++){
        
    }
    return timer;
}

int main(){
    std::vector<int> ticket_set1 = {2, 3, 2};
    std::vector<int> ticket_set1 = {5, 1, 1, 1};
    std::vector<int> ticket_set1 = {1};
    return 0;
}