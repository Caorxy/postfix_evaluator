#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

float performOperation(char operation, float a, float b) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: throw invalid_argument("Unknown operation");
    }
}

float performUnaryOperation(const string& operation, float a) {
    if (operation == "sqrt") return sqrt(a);
    if (operation == "sin") return sin(a);
    if (operation == "cos") return cos(a);
    if (operation == "~") return -a;
    throw invalid_argument("Unknown unary operation");
}

int main() {
    string input;

    cout << "Enter the expression in a postfix notation, separating consecutive elements with commas (for floating point numbers use . )\n";
    cin >> input;

    stack<float> stos;
    string tempint;
    bool itwasint = false;

    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        if (token.empty()) continue;

        if (isdigit(token[0]) || token[0] == '.' || (token[0] == '-' && isdigit(token[1]))) {
            stos.push(stof(token));
        } else if (token == "~" || token == "sqrt" || token == "sin" || token == "cos") {
            float operand = stos.top(); stos.pop();
            stos.push(performUnaryOperation(token, operand));
        } else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '^')) {
            float operand2 = stos.top(); stos.pop();
            float operand1 = stos.top(); stos.pop();
            stos.push(performOperation(token[0], operand1, operand2));
        } else {
            cerr << "Invalid token: " << token << endl;
            return 1;
        }
    }

    if (stos.size() != 1) {
        cerr << "Error in the input expression." << endl;
        return 1;
    }

    cout << "Result: " << stos.top() << endl;

    return 0;
}
