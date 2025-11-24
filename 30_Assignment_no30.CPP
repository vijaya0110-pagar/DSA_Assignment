#include <iostream>
#include <string>
using namespace std;

struct Call {
    int callID;
    string callerName;
    Call* next;
};

class CallCenterQueue {
private:
    Call* front;
    Call* rear;
    int nextID;

public:
    CallCenterQueue() {
        front = rear = nullptr;
        nextID = 1;
    }

    
    void enqueue(string name) {
        Call* newCall = new Call;
        newCall->callID = nextID++;
        newCall->callerName = name;
        newCall->next = nullptr;

        if (rear == nullptr) {
            front = rear = newCall;
        } else {
            rear->next = newCall;
            rear = newCall;
        }

        cout << "📞 Call from " << name << " (ID: " << newCall->callID << ") has been added to the queue.\n";
    }

    
    void dequeue() {
        if (front == nullptr) {
            cout << "⚠️ No calls in the queue. Waiting for new calls...\n";
            return;
        }

        Call* temp = front;
        cout << "🎧 Serving Call ID " << temp->callID << " from " << temp->callerName << ".\n";
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete temp;
    }

   
    void displayQueue() {
        if (front == nullptr) {
            cout << "📭 No calls waiting in the queue.\n";
            return;
        }

        cout << "\n📋 Current Waiting Calls:\n";
        Call* temp = front;
        while (temp != nullptr) {
            cout << "   ▶ Call ID: " << temp->callID << ", Name: " << temp->callerName << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    CallCenterQueue queue;
    int choice;
    string name;

    do {
        cout << "\n======= CALL CENTER QUEUE SYSTEM =======\n";
        cout << "1. New Call Arrives (Enqueue)\n";
        cout << "2. Agent Answers Call (Dequeue)\n";
        cout << "3. Display Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Caller Name: ";
                cin >> name;
                queue.enqueue(name);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.displayQueue();
                break;

            case 4:
                cout << "👋 Exiting the system...\n";
                break;

            default:
                cout << "❌ Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
