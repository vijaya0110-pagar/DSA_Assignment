#include <iostream>
#include <string>
using namespace std;


struct Patient {
    int id;
    string name;
    string problem;
    Patient* next;
};


class ClinicQueue {
private:
    Patient* front;
    Patient* rear;
    int patientCount;

public:
    ClinicQueue() {
        front = rear = nullptr;
        patientCount = 0;
    }

    
    void checkIn(int id, string name, string problem) {
        Patient* newPatient = new Patient();
        newPatient->id = id;
        newPatient->name = name;
        newPatient->problem = problem;
        newPatient->next = nullptr;

        if (rear == nullptr) {  
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }

        patientCount++;
        cout << "\n✅ Patient " << name << " checked in successfully.\n";
    }

   
    void assignDoctor() {
        if (front == nullptr) {
            cout << "\n⚠️  No patients waiting.\n";
            return;
        }

        Patient* temp = front;
        cout << "\n👩‍⚕️ Assigning Doctor to Patient: "
             << temp->name << " (ID: " << temp->id << ", Problem: " << temp->problem << ")\n";

        front = front->next;
        if (front == nullptr) rear = nullptr;

        delete temp;
        patientCount--;
    }

   
    void displayQueue() {
        if (front == nullptr) {
            cout << "\n🕓 No patients currently waiting.\n";
            return;
        }

        cout << "\n🧾 Current Waiting List:\n";
        Patient* temp = front;
        while (temp != nullptr) {
            cout << "  ID: " << temp->id << ", Name: " << temp->name
                 << ", Problem: " << temp->problem << endl;
            temp = temp->next;
        }
    }

   
    void countPatients() {
        cout << "\n📊 Total Patients Waiting: " << patientCount << endl;
    }
};


int main() {
    ClinicQueue clinic;
    int choice, id;
    string name, problem;

    do {
        cout << "\n====== 🏥 MEDICAL CLINIC QUEUE SYSTEM ======\n";
        cout << "1. Check-in New Patient\n";
        cout << "2. Assign Doctor to Next Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Count Waiting Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Problem Description: ";
            cin >> problem;
            clinic.checkIn(id, name, problem);
            break;

        case 2:
            clinic.assignDoctor();
            break;

        case 3:
            clinic.displayQueue();
            break;

        case 4:
            clinic.countPatients();
            break;

        case 5:
            cout << "\n👋 Exiting system. Have a nice day!\n";
            break;

        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
