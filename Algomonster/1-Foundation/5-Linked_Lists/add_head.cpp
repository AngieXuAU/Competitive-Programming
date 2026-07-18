#include <iostream>

// node struct
template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

// function for pretty printing of linked list to view result
void pprint_node(Node<int> *head) {
    while ((head->next) != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << head->val;
}

// insert function
Node<int> *insert_at_head(Node<int> *head, int value) {
    Node<int> *new_head = new Node<int>{value};
    new_head->next = head;
    return new_head;
}

// main function, run for testing
int main() {
    Node<int> *initial_head = new Node<int>(3);
    Node<int> *second = new Node<int>(6);
    initial_head->next = second;

    Node<int> *new_head = insert_at_head(initial_head, 0);
    pprint_node(new_head);

    return 0;
}