
#include <iostream>
using namespace std;

#define MAX 5  
class MultiQueue {
private:
    int q1[MAX], q2[MAX]; 
    int front1, rear1, front2, rear2;

public:
    MultiQueue() {
        front1 = rear1 = -1;
        front2 = rear2 = -1;
    }

    
    void addQueue1(int value) {
        if (rear1 == MAX - 1)
            cout << "\n⚠️ Queue 1 Overflow!\n";
        else {
            if (front1 == -1) front1 = 0;
            q1[++rear1] = value;
            cout << "\n✅ Inserted " << value << " in Queue 1\n";
        }
    }

    void deleteQueue1() {
        if (front1 == -1 || front1 > rear1)
            cout << "\n⚠️ Queue 1 Underflow!\n";
        else {
            cout << "\n🗑️ Deleted " << q1[front1] << " from Queue 1\n";
            front1++;
        }
    }

    void displayQueue1() {
        if (front1 == -1 || front1 > rear1)
            cout << "\nQueue 1 is Empty.\n";
        else {
            cout << "\nQueue 1 Elements: ";
            for (int i = front1; i <= rear1; i++)
                cout << q1[i] << " ";
            cout << endl;
        }
    }

    
    void addQueue2(int value) {
        if (rear2 == MAX - 1)
            cout << "\n⚠️ Queue 2 Overflow!\n";
        else {
            if (front2 == -1) front2 = 0;
            q2[++rear2] = value;
            cout << "\n✅ Inserted " << value << " in Queue 2\n";
        }
    }

    void deleteQueue2() {
        if (front2 == -1 || front2 > rear2)
            cout << "\n⚠️ Queue 2 Underflow!\n";
        else {
            cout << "\n🗑️ Deleted " << q2[front2] << " from Queue 2\n";
            front2++;
        }
    }

    void displayQueue2() {
        if (front2 == -1 || front2 > rear2)
            cout << "\nQueue 2 is Empty.\n";
        else {
            cout << "\nQueue 2 Elements: ";
            for (int i = front2; i <= rear2; i++)
                cout << q2[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    MultiQueue mq;
    int choice, qno, value;

    do {
        cout << "\n====== MULTIPLE QUEUE SYSTEM ======\n";
        cout << "1. Add Element to Queue\n";
        cout << "2. Delete Element from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Queue number (1 or 2): ";
            cin >> qno;
            cout << "Enter value to insert: ";
            cin >> value;
            if (qno == 1) mq.addQueue1(value);
            else if (qno == 2) mq.addQueue2(value);
            else cout << "❌ Invalid Queue number!\n";
            break;

        case 2:
            cout << "Enter Queue number (1 or 2): ";
            cin >> qno;
            if (qno == 1) mq.deleteQueue1();
            else if (qno == 2) mq.deleteQueue2();
            else cout << "❌ Invalid Queue number!\n";
            break;

        case 3:
            cout << "Enter Queue number (1 or 2): ";
            cin >> qno;
            if (qno == 1) mq.displayQueue1();
            else if (qno == 2) mq.displayQueue2();
            else cout << "❌ Invalid Queue number!\n";
            break;

        case 4:
            cout << "\n👋 Exiting program...\n";
            break;

        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
