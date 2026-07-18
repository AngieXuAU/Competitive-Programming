
struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;

    // third -> next is nullptr by default
    return 0;
}