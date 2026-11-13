#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    int num;
    cout << "How many random numbers do you want? ";
    cin >> num;

    cout << "What is the minimum wanted number? ";
    int min;
    cin >> min;
    cout << "What is the maximum wanted number? ";
    int max;
    cin >> max;

    uniform_int_distribution<int> intDist(min, max);

    cout << num << " ";
    for (int i = 0; i < num; i++) {
        cout << intDist(gen) << " ";
    }
}