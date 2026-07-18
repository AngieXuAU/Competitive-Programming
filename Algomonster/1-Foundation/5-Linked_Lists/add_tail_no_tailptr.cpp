#include <iostream>

// node struct, maintaining tail pointer
template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {};
};

Node<int> *insert_at_tail(Node<int> *head, int value) {
    Node<int> *current = head;
    while (current->next != nullptr) {
        current = current->next;
    } // current is now holding the memory of the last node

    Node<int> *new_tail = new Node<int>{value};
    current->next = new_tail;

    return head;
}

void pprint(Node<int> *head) {
    Node<int> *current = head;
    while (current->next != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << current->val;
}

// executable
int main() {
    // initialise nodes
    Node<int> *head = new Node(2);
    Node<int> *second = new Node(4);
    Node<int> *third = new Node(6);

    // link them
    head->next = second;
    second->next = third;

    // insert new
    Node<int> *new_linkedls = insert_at_tail(head, 8);

    // print to check results
    pprint(new_linkedls);
    return 0;
}