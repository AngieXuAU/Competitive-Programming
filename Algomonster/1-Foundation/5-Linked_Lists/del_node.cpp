#include <iostream>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

Node<int> *delete_node(Node<int> *head, int value) {
    if (head == nullptr) {
        return nullptr;
    }

    Node<int> *current = head;

    if (current->val == value) { // if target in 1st node
        Node<int> *new_head = current->next;
        delete head;
        return new_head; // new head is pointer to 2nd node
    }

    while (current->next != nullptr) {
        if (current->next->val == value) {
            Node<int> *to_delete = current->next;
            current->next = current->next->next;

            delete to_delete; // IMPORTANT: FREE MEMORY
            return head;
        }
        current = current->next;
    }

    return head;
}

void pprint(Node<int> *head) {
    if (head == nullptr) {
        std::cout << "Empty linked list :(";
        return;
    }
    Node<int> *current = head;
    while (current->next != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << current->val;
}

int main() {
    Node<int> *fifth = new Node<int>{5};
    Node<int> *fourth = new Node<int>{4, fifth};
    Node<int> *third = new Node<int>{3, fourth};
    Node<int> *second = new Node<int>{2, third};
    Node<int> *head = new Node<int>{1, second};

    pprint(delete_node(head, 1));

    // previous testing
    // std::cout << "Edge case 1: delete a nullptr: ";
    // pprint(delete_node(nullptr, 7)); // seg fault :(

    // // std::cout << "Edge case 2: target in 1st: ";

    // std::cout << "\nEdge case 3: target in last: ";
    // pprint(delete_node(head, 16));
}