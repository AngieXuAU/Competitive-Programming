
#include <iostream>

using namespace std;

template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

int count_nodes(Node<int> *head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 1;
    Node<int> *subsequent = head->next;
    while (subsequent != nullptr) {
        count++;
        subsequent = subsequent->next;
    }

    return count;
}

int main() {
    Node<int> *head1 = new Node<int>{2};
    Node<int> *val2 = new Node<int>{4};
    Node<int> *val3 = new Node<int>{6};

    head1->next = val2;
    val2->next = val3;

    cout << count_nodes(head1);

    return 0;
}