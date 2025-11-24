#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;


int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  
    }
    return 0;
}


int evaluatePostfix(string expr) {
    stack<int> s;

    for (char ch : expr) {
        
        if (isdigit(ch)) {
            s.push(ch - '0');  
        }
        
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            int result = applyOperation(val1, val2, ch);
            s.push(result);
        }
    }

    
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
