
template <typename T> struct Node {
    T val;
    Node<T> *left;
    Node<T> *right;

    explicit Node(T val, Node<T> *left = nullptr, Node<T> *right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};