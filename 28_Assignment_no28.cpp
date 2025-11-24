#include <iostream>
#include <string>
using namespace std;


struct Passenger {
    int id;
    string name;
    Passenger* next;
};


class PassengerQueue {
private:
    Passenger* front;
    Passenger* rear;
    int count;

public:
    PassengerQueue() {
        front = rear = nullptr;
        count = 0;
    }

    
    void addPassenger(int id, string name) {
        Passenger* newPassenger = new Passenger();
        newPassenger->id = id;
        newPassenger->name = name;
        newPassenger->next = nullptr;

        if (rear == nullptr) {  
            front = rear = newPassenger;
        } else {
            rear->next = newPassenger;
            rear = newPassenger;
        }

        count++;
        cout << "\n✅ Passenger " << name << " (ID: " << id << ") added to queue.\n";
    }

    
    void showFrontPassenger() {
        if (front == nullptr) {
            cout << "\n⚠️  No passengers in the queue.\n";
            return;
        }
        cout << "\n🎟️  Next Passenger: " << front->name << " (ID: " << front->id << ")\n";
    }

    
    void servePassenger() {
        if (front == nullptr) {
            cout << "\n⚠️  Queue is empty. No passenger to serve.\n";
            return;
        }

        Passenger* temp = front;
        cout << "\n👩‍💼 Serving Passenger: " << temp->name << " (ID: " << temp->id << ")\n";

        front = front->next;
        if (front == nullptr)
            rear = nullptr;

        delete temp;
        count--;
    }

    
    void showRemainingPassengers() {
        cout << "\n🧾 Number of passengers left in the queue: " << count << endl;
    }
};


int main() {
    PassengerQueue queue;
    int choice, id = 1;
    string name;

    do {
        cout << "\n====== 🚆 TICKET AGENT QUEUE SYSTEM ======\n";
        cout << "1. Add New Passenger\n";
        cout << "2. Show Next Passenger\n";
        cout << "3. Serve Passenger\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Passenger Name: ";
            cin >> name;
            queue.addPassenger(id++, name);
            break;

        case 2:
            queue.showFrontPassenger();
            break;

        case 3:
            queue.servePassenger();
            break;

        case 4:
            queue.showRemainingPassengers();
            cout << "\n👋 System closing. Have a nice day!\n";
            break;

        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
