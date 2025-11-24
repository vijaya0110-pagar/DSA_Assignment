#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
      
    }

    
    return s.empty();
}


int main() {
    string expr;
    cout << "Enter a string of brackets: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "✅ The parentheses are BALANCED.\n";
    else
        cout << "❌ The parentheses are NOT balanced.\n";

    return 0;
}
