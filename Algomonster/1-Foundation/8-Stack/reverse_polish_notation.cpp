#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

std::string operate(std::string x, std::string y, std::string c) {
    int a = std::stoi(x), b = std::stoi(y), result;

    switch (c[0]) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }

    return std::to_string(result);
}

int eval_rpn(std::vector<std::string> &tokens) {
    std::unordered_set<std::string> operands = {"+", "-", "*", "/"};
    std::stack<std::string> equation;

    for (std::string token : tokens) {
        if (operands.count(token)) {
            std::string y = equation.top();
            equation.pop();
            std::string x = equation.top();
            equation.pop();

            equation.push(operate(x, y, token));

        } else {
            equation.push(token);
        }
    }

    return std::stoi(equation.top());
}

int main() {
    std::vector<std::string> input = {"2", "1", "+", "3", "*"};
    std::cout << eval_rpn(input);

    return 0;
}