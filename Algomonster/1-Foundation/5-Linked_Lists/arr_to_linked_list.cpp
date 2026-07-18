// #include <iostream>
#include <vector>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}

    ~Node() { delete next; }
};

Node<int> *create_linked_list(std::vector<int> &values) {
    if (values.empty()) {
        return nullptr;
    }

    Node<int> *header = new Node<int>{values[0]}; // initialise the head
    Node<int> *previous = header; // initialise previous for first iteration

    for (int i = 1; i < values.size(); i++) {
        Node<int> *current = new Node<int>{values[i]}; // create a new node
        previous->next = current;                      // link to previous
        previous = current; // save node as previous for next link
    }
    return header;
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10};
    return 0;
}

// for (int i = 1; i < values.size(); i++){

// }
