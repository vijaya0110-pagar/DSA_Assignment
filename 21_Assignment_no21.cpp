#include <iostream>
using namespace std;


struct Node {
    int price;
    Node* next;
    Node(int p) {
        price = p;
        next = NULL;
    }
};


class StockStack {
private:
    Node* top;  
public:
    StockStack() {
        top = NULL;
    }

    
    void record(int price) {
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout << "Recorded price: " << price << endl;
    }

    
    int remove() {
        if (isEmpty()) {
            cout << "No prices to remove! Stack is empty.\n";
            return -1;
        }
        int removedPrice = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Removed most recent price: " << removedPrice << endl;
        return removedPrice;
    }

    int latest() {
        if (isEmpty()) {
            cout << "No prices recorded yet!\n";
            return -1;
        }
        cout << "Latest recorded price: " << top->price << endl;
        return top->price;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    
    void display() {
        if (isEmpty()) {
            cout << "No prices recorded.\n";
            return;
        }
        cout << "Stock price history (latest first): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->price << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    StockStack tracker;
    int choice, price;

    cout << "===== Stock Price Tracker (using Stack - Linked List) =====\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Record a new price\n";
        cout << "2. Remove the most recent price\n";
        cout << "3. View the latest price\n";
        cout << "4. Check if no prices are recorded\n";
        cout << "5. Display all recorded prices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stock price to record: ";
            cin >> price;
            tracker.record(price);
            break;
        case 2:
            tracker.remove();
            break;
        case 3:
            tracker.latest();
            break;
        case 4:
            if (tracker.isEmpty())
                cout << "No prices recorded (stack is empty).\n";
            else
                cout << "There are prices recorded.\n";
            break;
        case 5:
            tracker.display();
            break;
        case 0:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
