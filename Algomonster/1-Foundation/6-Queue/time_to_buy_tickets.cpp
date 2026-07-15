
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int time_required_to_buy(std::vector<int>& tickets, int k) {
    int timer = 0;
    int tickets_wanted = tickets[k];            // using index of target for # of tickets
    int limit = k + (tickets_wanted - 1) * tickets.size();    // how many times to loop
    // case 1: 2 + (1) * 3 = 5 // wanna rotate 5 times // go from 0-5
    std::queue<int> q;

    for (int x: tickets){           // make the queue from the vector
        q.push(x);
    }

    for (int i = 0; i <= limit; i++){
        // prints out the queue for debugging purposes
        // std::queue<int> tq = q;
        // while (!tq.empty()){
        //     int io = tq.front();
        //     std::cout << io << "\t";
        //     tq.pop();
        // }
        // std::cout << "\n====================================" << std::endl;

        int temp = q.front();
        if (temp > 0){        // front person takes 1 unit of time to buy ticket
            timer ++;
        }
        // whatever the case, we need to rotate the queue
        q.pop();
        q.push(temp > 0? (temp-1):0);
        
    }

    return timer;
}

int main(){
    std::vector<int> ticket_set1 = {2, 3, 2};
    std::vector<int> ticket_set2 = {5, 1, 1, 1};
    std::vector<int> ticket_set3 = {1};


    std::cout << time_required_to_buy(ticket_set1, 2) << "\t" 
    << time_required_to_buy(ticket_set2, 0) << "\t"
    << time_required_to_buy(ticket_set3, 0) << "\t"
    ;

    return 0;
}