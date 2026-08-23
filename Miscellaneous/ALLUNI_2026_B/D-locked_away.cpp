#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    Node *next;

    explicit Node(int val, Node *next = nullptr) : val{val}, next{next} {}
};

int main() {
    int num_locks, num_removals;

    cin >> num_locks >> num_removals;

    // cin numbers to be removed into set
    unordered_set<int> remove = {};
    int tmp;
    for (int i = 0; i < num_removals; i++) {
        cin >> tmp;
        remove.insert(tmp);
    }

    // create linked list
    Node *tail = new Node{num_locks};
    Node *previous = tail;
    for (int j = num_locks - 1; j > 0; j--) {
        Node *input = new Node{j, previous};
        previous = input;
    }
    Node *head = new Node{0, previous};
    Node *current = head;

    // traverse and delete
    set<Node *> heads = {previous};

    // find the first head

    // find the other heads
    while (current->next != nullptr) {
        if (remove.count(current->next->val)) {
            heads.erase(current->next);
            if (current->next->next != nullptr) {
                heads.insert(current->next->next);
            }
        }
        current = current->next;
    }

    cout << heads.size();
    return 0;
}