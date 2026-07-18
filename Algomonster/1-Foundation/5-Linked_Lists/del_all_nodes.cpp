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

    // create a dummy head node so that first deletions are not edge cases
    Node<int> *dummy = new Node<int>{-1, head};
    Node<int> *current = dummy;

    while (current->next != nullptr) {
        while (current->next->val == value) { // if->while: consecutive matches
            Node<int> *to_delete = current->next;
            current->next = current->next->next;

            delete to_delete; // IMPORTANT: FREE MEMORY

            if (current->next == nullptr) { // manual break: del of last node
                break;
            }
        }
        if (current->next == nullptr) { // manual break: del of last node
            break;
        }
        current = current->next;
    }

    Node<int> *new_head = dummy->next;
    delete dummy;
    return new_head;
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
    Node<int> *sixth = new Node<int>{9};
    Node<int> *fifth = new Node<int>{9, sixth};
    Node<int> *fourth = new Node<int>{9, fifth};
    Node<int> *third = new Node<int>{9, fourth};
    Node<int> *second = new Node<int>{9, third};
    Node<int> *head = new Node<int>{9, second};

    pprint(delete_node(head, 9));

    // previous testing
    // std::cout << "Edge case 1: delete a nullptr: ";
    // pprint(delete_node(nullptr, 7)); // seg fault :(

    // // std::cout << "Edge case 2: target in 1st: ";

    // std::cout << "\nEdge case 3: target in last: ";
    // pprint(delete_node(head, 16));
}