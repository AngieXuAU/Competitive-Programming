#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int operate(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 1;
    }
}
int evalRPN(vector<string> &tokens) {
    stack<int> vals;

    int tmp;
    int initial = stoi(tokens[0]);

    vals.push(initial);

    for (int i = 1; i < tokens.size(); i++) {
        try {
            tmp = stoi(tokens[i]);
            vals.push(tmp);
        } catch (const invalid_argument &e) {
            char op = (char)tokens[i].at(0);

            int y = vals.top();
            vals.pop();
            int x = vals.top();
            vals.pop();
            tmp = operate(x, y, op);
            vals.push(tmp);
        }
    }

    int result = vals.top();
    return result;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n;
        cin >> n;
        vector<string> vec;
        for (int j = 0; j < n; j++) {
            string tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        cout << evalRPN(vec) << "\n";
    }
    return 0;
}