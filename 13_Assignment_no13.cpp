#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Appointment {
    int start;   
    int end;
    bool booked;
    Appointment* next;
};

class Schedule {
    Appointment* head;
    int startDay, endDay, minDur, maxDur;

public:
    Schedule(int startT, int endT, int minD, int maxD) {
        head = NULL;
        startDay = startT;
        endDay = endT;
        minDur = minD;
        maxDur = maxD;
        createSlots();
        randomBookings();
    }

    
    string formatTime(int time) {
        int h = time / 60;
        int m = time % 60;
        string ampm = (h >= 12) ? "PM" : "AM";
        if (h > 12) h -= 12;
        if (h == 0) h = 12;
        char buf[10];
        sprintf(buf, "%02d:%02d %s", h, m, ampm.c_str());
        return string(buf);
    }

   
    void createSlots() {
        for (int t = startDay; t + minDur <= endDay; t += minDur) {
            Appointment* node = new Appointment();
            node->start = t;
            node->end = t + minDur;
            node->booked = false;
            node->next = NULL;

            if (head == NULL)
                head = node;
            else {
                Appointment* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = node;
            }
        }
    }

  
    void randomBookings() {
        srand(time(0));
        Appointment* temp = head;
        while (temp) {
            if (rand() % 3 == 0)
                temp->booked = true;
            temp = temp->next;
        }
    }

    
    void display() {
        cout << "\n--- Appointment Schedule ---\n";
        cout << left << setw(15) << "Start Time"
             << setw(15) << "End Time"
             << setw(10) << "Status" << endl;
        cout << "---------------------------------------------\n";

        Appointment* temp = head;
        while (temp) {
            cout << left << setw(15) << formatTime(temp->start)
                 << setw(15) << formatTime(temp->end)
                 << setw(10) << (temp->booked ? "Booked" : "Free") << endl;
            temp = temp->next;
        }
    }

   
    void displayAvailable() {
        cout << "\n--- Available Slots ---\n";
        Appointment* temp = head;
        bool found = false;
        while (temp) {
            if (!temp->booked) {
                cout << "From " << formatTime(temp->start)
                     << " to " << formatTime(temp->end) << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "No available slots!\n";
    }

    
    void bookAppointment() {
        int h, m;
        cout << "Enter start time to book (HH MM in 24-hour): ";
        cin >> h >> m;
        int startTime = h * 60 + m;

        Appointment* temp = head;
        while (temp) {
            if (temp->start == startTime) {
                if (temp->booked)
                    cout << "Slot already booked!\n";
                else {
                    temp->booked = true;
                    cout << "Appointment booked successfully!\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid slot time!\n";
    }

    
    void cancelAppointment() {
        int h, m;
        cout << "Enter start time to cancel (HH MM in 24-hour): ";
        cin >> h >> m;
        int startTime = h * 60 + m;

        Appointment* temp = head;
        while (temp) {
            if (temp->start == startTime) {
                if (!temp->booked)
                    cout << "Slot is not booked!\n";
                else {
                    temp->booked = false;
                    cout << "Appointment cancelled successfully!\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid slot time!\n";
    }

   
    void sortByTime() {
        if (!head) return;
        for (Appointment* i = head; i->next != NULL; i = i->next) {
            for (Appointment* j = i->next; j != NULL; j = j->next) {
                if (i->start > j->start) {
                    swap(i->start, j->start);
                    swap(i->end, j->end);
                    swap(i->booked, j->booked);
                }
            }
        }
        cout << "List sorted by swapping data values!\n";
    }

   
    void sortByPointer() {
        if (!head || !head->next) return;

        Appointment* sorted = NULL;
        Appointment* current = head;

        while (current != NULL) {
            Appointment* next = current->next;
            if (sorted == NULL || current->start < sorted->start) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next != NULL && temp->next->start < current->start)
                    temp = temp->next;
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
        cout << "List sorted using pointer manipulation!\n";
    }
};


int main() {
    // Define working day: 9 AM (540 min) to 5 PM (1020 min)
    // Min duration: 60 minutes per slot, Max: 120
    Schedule s(540, 1020, 60, 120);
    int choice;

    cout << "\n🕒 Appointment Scheduling System 🗓️\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display All Slots\n";
        cout << "2. Display Available Slots\n";
        cout << "3. Book Appointment\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. Sort by Time (Data Swap)\n";
        cout << "6. Sort by Time (Pointer Manipulation)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.display();
            break;
        case 2:
            s.displayAvailable();
            break;
        case 3:
            s.bookAppointment();
            break;
        case 4:
            s.cancelAppointment();
            break;
        case 5:
            s.sortByTime();
            break;
        case 6:
            s.sortByPointer();
            break;
        case 0:
            cout << "Exiting... Have a great day!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
