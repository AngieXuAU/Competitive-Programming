#include <iostream>

template <typename T> struct DoublyNode {
    T val;
    DoublyNode<T> *next;
    DoublyNode<T> *prev;

    explicit DoublyNode(T val, DoublyNode<T> *next = nullptr,
                        DoublyNode<T> *previous = nullptr)
        : val{val}, next{next}, prev{previous} {}
};

void pprint(DoublyNode<int> *head) {
    if (head == nullptr) {
        std::cout << "Empty linked list :(";
        return;
    }
    DoublyNode<int> *current = head;
    while (current->next != nullptr) {
        std::cout << current->val << " <-> ";
        current = current->next;
    }
    std::cout << current->val << std::endl;
}

void pprint_backwards(DoublyNode<int> *head) {
    if (head == nullptr) {
        std::cout << "Empty linked list :(";
        return;
    }
    DoublyNode<int> *current = head;
    while (current->prev != nullptr) {
        std::cout << current->val << " <-> ";
        current = current->prev;
    }
    std::cout << current->val << std::endl;
}

DoublyNode<int> *reverse_doubly_linked_list(DoublyNode<int> *head) {
    // edge case: linked list length 1
    if (head->next == nullptr) {
        return head;
    }

    // the first node
    head->prev = head->next;
    head->next = nullptr;
    DoublyNode<int> *current = head->prev;

    // middle nodes
    while (current->next != nullptr) {
        auto temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = current->prev;
    }

    current->next = current->prev;
    current->prev = nullptr;

    return current;
}

int main() {
    DoublyNode<int> *head = new DoublyNode<int>{1};
    // DoublyNode<int> *second = new DoublyNode<int>{2};
    // DoublyNode<int> *tail = new DoublyNode<int>{2};

    // head->next = tail;
    // second->previous = head;

    // second->next = tail;
    // tail->previous = head;

    pprint(head);
    pprint(reverse_doubly_linked_list(head));
}