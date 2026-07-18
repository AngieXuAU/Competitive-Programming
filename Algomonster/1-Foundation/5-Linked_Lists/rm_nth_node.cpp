#include <iostream>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

Node<int> *remove_nth_node(Node<int> *head, int n) {
    // edge case: delete first
    if (n == 1) {
        Node<int> *new_head = head->next;
        delete head;
        return new_head;
    }

    // main loop
    Node<int> *current = head;
    for (int i = 1; i < n - 1; i++) {
        current = current->next;
    }
    // deletion
    Node<int> *tb_del = current->next;
    current->next = tb_del->next;
    delete tb_del;

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
    Node<int> *third = new Node<int>{3};
    Node<int> *second = new Node<int>{2, third};
    Node<int> *head = new Node<int>{1, second};

    Node<int> *other_head = new Node<int>{1};

    pprint(remove_nth_node(head, 1));
    pprint(remove_nth_node(other_head, 1));
}