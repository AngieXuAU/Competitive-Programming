
#include <iostream>
#include <string>
#include <queue>
#include <vector>

void pprint(std::queue<int> q_result){
    std::vector<int> vec_result;
    while(!q_result.empty()){
        int temp = q_result.front();
        vec_result.push_back(temp);
        q_result.pop();
    }
    for (int item: vec_result){
        std::cout << item << "\t";
    }

    std::cout << std::endl;
}

std::queue <int> q_operation(std::vector <std::string>& program){
    std::queue<int> q;

    for (std::string& instruction: program){
        if (instruction == "peek"){
            if (!q.empty()){
                std::cout << q.front() << "\n";
            } else {
                std::cout << "Queue is empty!\n";
            }
        } else if (instruction == "pop"){
            if (!q.empty()){
                q.pop();
            } else {
                std::cout << "Queue is empty!\n";
            }
        } else {
            int num = std::stoi(instruction.substr(5));
            q.push(num);
        }
    }

    return q;
}


int main(){
    std::vector<std::string> program = {"push 3", "push 7", "peek", "pop", "push 5"};
    std::queue<int> q = q_operation(program);
    
    pprint(q);

    return 0;
}