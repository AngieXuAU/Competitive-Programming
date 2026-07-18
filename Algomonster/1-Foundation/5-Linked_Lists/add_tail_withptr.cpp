#include <iostream>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {};
};

template <typename T> struct LinkedList {
    Node<T> *head;
    Node<T> *tail;

    explicit LinkedList(Node<T> *head = nullptr, Node<T> *tail = nullptr)
        : head{head}, tail{tail} {};
};

LinkedList<int> add_tail(LinkedList<int> linked_ls, int value) {
    Node<int> *old_tail = linked_ls.tail;

    Node<int> *new_tail = new Node<int>{value}; // initialise node for new tail
    old_tail->next = new_tail;                  // link old and new tails

    linked_ls.tail = new_tail; // update tail value of linked list
    return linked_ls;
}

void pprint(Node<int> *head) {
    Node<int> *current = head;
    while (current->next != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << current->val;
}

int main() {
    // initialising nodes
    Node<int> *head = new Node<int>{10};
    Node<int> *second = new Node<int>{20};
    Node<int> *third = new Node<int>{30};

    // linking them
    head->next = second;
    second->next = third;

    // initialising linked list struct with head and tail
    LinkedList<int> linked_ls = LinkedList<int>{head, third};

    add_tail(linked_ls, 40);
    pprint(head);

    return 0;
}