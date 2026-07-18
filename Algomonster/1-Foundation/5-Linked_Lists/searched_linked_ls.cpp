#include <iostream>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

int search_linked_list(Node<int> *head, int target) {
    if (head == nullptr) {
        return 0;
    }

    Node<int> *current = head;
    while (current->next != nullptr) {
        if (current->val == target) {
            return 1;
        }
        current = current->next;
    }

    // loop escaped when current = last, check last
    if (current->val == target) {
        return 1;
    }

    return 0;
}

int main() {
    Node<int> *third = new Node<int>{18};
    Node<int> *second = new Node<int>{12, third};
    Node<int> *head = new Node<int>{6, second};

    std::cout << search_linked_list(head, 6) << search_linked_list(head, 12)
              << search_linked_list(head, 18) << search_linked_list(head, 7);
}