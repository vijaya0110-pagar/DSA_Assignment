#include <iostream>
using namespace std;

#define MAX 30   

class MultiStack {
    int arr[MAX];      
    int top[10];       
    int nStacks;       
    int size;          

public:
    
    MultiStack(int n) {
        nStacks = n;
        size = MAX / nStacks;

        
        for (int i = 0; i < nStacks; i++) {
            top[i] = (i * size) - 1; 
        }
    }

    
    void push(int stackNum, int value) {
        if (stackNum < 1 || stackNum > nStacks) {
            cout << "Invalid stack number!\n";
            return;
        }

        int limit = stackNum * size - 1;

        if (top[stackNum - 1] == limit) {
            cout << "Stack Overflow in Stack " << stackNum << "!\n";
            return;
        }

        top[stackNum - 1]++;
        arr[top[stackNum - 1]] = value;
        cout << "Pushed " << value << " into Stack " << stackNum << endl;
    }

    
    void pop(int stackNum) {
        if (stackNum < 1 || stackNum > nStacks) {
            cout << "Invalid stack number!\n";
            return;
        }

        int start = (stackNum - 1) * size;

        if (top[stackNum - 1] < start) {
            cout << "Stack Underflow in Stack " << stackNum << "!\n";
            return;
        }

        int popped = arr[top[stackNum - 1]];
        top[stackNum - 1]--;
        cout << "Popped " << popped << " from Stack " << stackNum << endl;
    }

    
    void display() {
        cout << "\n=== Stack Status ===\n";
        for (int i = 0; i < nStacks; i++) {
            cout << "Stack " << i + 1 << ": ";
            int start = i * size;
            if (top[i] < start) {
                cout << "(empty)";
            } else {
                for (int j = start; j <= top[i]; j++) {
                    cout << arr[j] << " ";
                }
            }
            cout << endl;
        }
    }
};


int main() {
    int n;
    cout << "Enter number of stacks to create (max 10): ";
    cin >> n;

    MultiStack ms(n);

    int choice, stackNum, value;
    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Push\n2. Pop\n3. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stack number (1-" << n << "): ";
            cin >> stackNum;
            cout << "Enter value to push: ";
            cin >> value;
            ms.push(stackNum, value);
            break;

        case 2:
            cout << "Enter stack number (1-" << n << "): ";
            cin >> stackNum;
            ms.pop(stackNum);
            break;

        case 3:
            ms.display();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
