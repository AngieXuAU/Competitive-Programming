#include <iostream>

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

Node<int> *delete_node_without_head(Node<int> *head, int position) {
    // delete 1st node
    if (position == 1) {
        Node<int> *new_head = head->next;
        delete head;
        return new_head;
    }

    // traverse to spot
    Node<int> *current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    Node<int> *tb_del = current->next;
    current->val = current->next->val;
    current->next = current->next->next;
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
    std::cout << current->val << std::endl;
}

int main() {
    Node<int> *sixth = new Node<int>{6};
    Node<int> *fifth = new Node<int>{5, sixth};
    Node<int> *fourth = new Node<int>{4, fifth};
    Node<int> *third = new Node<int>{3, fourth};
    Node<int> *second = new Node<int>{2, third};
    Node<int> *head = new Node<int>{1, second};

    pprint(delete_node_without_head(head, 6));
    // for (int target = 1; target <= 6; target++) {
    //     pprint(delete_node_without_head(head, target));
    // }

    // previous testing
    // std::cout << "Edge case 1: delete a nullptr: ";
    // pprint(delete_node(nullptr, 7)); // seg fault :(

    // // std::cout << "Edge case 2: target in 1st: ";

    // std::cout << "\nEdge case 3: target in last: ";
    // pprint(delete_node(head, 16));
}