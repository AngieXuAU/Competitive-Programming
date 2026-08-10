
template <typename T> struct Node {
    T val;
    Node<T> *next;

    explicit Node(T val, Node<T> *next = nullptr) : val{val}, next{next} {}
};

int middle_of_linked_list(Node<int> *head) {
    if (head == nullptr) {
        return -1;
    }

    Node<int> *fast = head;
    Node<int> *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    return slow->val;
}