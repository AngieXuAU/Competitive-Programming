#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <class T> void pprint(const std::vector<T> &vec) {
    for (T x : vec) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
}

void reverseString(vector<char> &s) {
    int tail = s.size() - 1;
    int i = 0;

    while (i < tail) {
        swap(s.at(i), s.at(tail));
        i++;
        tail--;
    }
}

int main() {
    vector<char> vec = {'h', 'e', 'l', 'l'};
    vector<char> vec2 = {'h', 'e', 'l', 'l', 'o'};
    reverseString(vec);
    reverseString(vec2);
    pprint(vec);
    pprint(vec2);
    return 0;
}