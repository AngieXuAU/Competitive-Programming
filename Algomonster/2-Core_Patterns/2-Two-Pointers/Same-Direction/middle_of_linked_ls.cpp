
template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

int middle_of_linked_list(Node<int> *head) {
    Node<int> *front = head;
    Node<int> *back = head;
    int i = 0;
    while (front->next != nullptr) {
        front = front->next;
        i++;
        if (i % 2 == 0) {
            back = back->next;
        }
    }
    if (i % 2 == 0) {
        return back->val;
    }
    return back->next->val;
}