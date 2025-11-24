#include <iostream>
using namespace std;

#define MAX 5 

class PizzaParlour {
private:
    int orders[MAX];
    int front, rear;

public:
    PizzaParlour() {
        front = rear = -1;
    }

    
    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

   
    bool isEmpty() {
        return (front == -1);
    }

    void placeOrder(int order_id) {
        if (isFull()) {
            cout << "\n⚠️ Sorry! Cannot accept more orders. Queue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        orders[rear] = order_id;
        cout << "\n✅ Order #" << order_id << " placed successfully!\n";
    }

    
    void serveOrder() {
        if (isEmpty()) {
            cout << "\n⚠️ No orders to serve. Queue is empty.\n";
            return;
        }

        cout << "\n🍕 Serving Order #" << orders[front] << "...\n";

        if (front == rear) {  
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    
    void displayOrders() {
        if (isEmpty()) {
            cout << "\n🕓 No pending orders.\n";
            return;
        }

        cout << "\n📋 Current Pending Orders: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};


int main() {
    PizzaParlour parlour;
    int choice, id = 1;

    do {
        cout << "\n====== 🍕 PIZZA PARLOUR ORDER SYSTEM ======\n";
        cout << "1. Place New Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display All Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            parlour.placeOrder(id++);
            break;

        case 2:
            parlour.serveOrder();
            break;

        case 3:
            parlour.displayOrders();
            break;

        case 4:
            cout << "\n👋 Thank you! Pizza Parlour closing now.\n";
            break;

        default:
            cout << "\n❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
