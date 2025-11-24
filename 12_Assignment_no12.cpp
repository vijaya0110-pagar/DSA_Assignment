#include <iostream>
#include <cstdlib>
using namespace std;

class Seat {
public:
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;

    Seat(int no) {
        seatNo = no;
        booked = false;
        next = prev = NULL;
    }
};

class GalaxyMultiplex {
    Seat* head[8];  

public:
    GalaxyMultiplex() {
        
        for (int i = 0; i < 8; i++) {
            head[i] = NULL;
            createRow(i);
        }

        
        randomBookings();
    }

   
    void createRow(int row) {
        Seat* last = NULL;
        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat(i);
            if (head[row] == NULL) {
                head[row] = newSeat;
                head[row]->next = head[row];
                head[row]->prev = head[row];
                last = head[row];
            } else {
                newSeat->prev = last;
                newSeat->next = head[row];
                last->next = newSeat;
                head[row]->prev = newSeat;
                last = newSeat;
            }
        }
    }

   
    void randomBookings() {
        srand(time(0));
        for (int r = 0; r < 8; r++) {
            int randomBooked = rand() % 4;  // 0–3 seats booked per row
            for (int i = 0; i < randomBooked; i++) {
                int seatNo = (rand() % 8) + 1;
                bookSeat(r + 1, seatNo, false);  // false = skip message
            }
        }
    }

    
    void display() {
        cout << "\n--- Seat Availability (0 = Free, X = Booked) ---\n";
        for (int r = 0; r < 8; r++) {
            cout << "Row " << r + 1 << ": ";
            Seat* temp = head[r];
            for (int i = 0; i < 8; i++) {
                cout << (temp->booked ? "X " : "0 ");
                temp = temp->next;
            }
            cout << endl;
        }
    }

   
    void bookSeat(int row, int seatNo, bool showMsg = true) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid seat/row number!\n";
            return;
        }

        Seat* temp = head[row - 1];
        for (int i = 1; i < seatNo; i++)
            temp = temp->next;

        if (temp->booked) {
            if (showMsg)
                cout << "Seat already booked!\n";
        } else {
            temp->booked = true;
            if (showMsg)
                cout << "Seat booked successfully (Row " << row << ", Seat " << seatNo << ")!\n";
        }
    }

   
    void bookMultipleSeats() {
        int row, n;
        cout << "Enter row number (1–8): ";
        cin >> row;
        cout << "How many seats to book? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int seatNo;
            cout << "Enter seat number (1–8): ";
            cin >> seatNo;
            bookSeat(row, seatNo);
        }
    }

   
    void cancelSeat(int row, int seatNo) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid seat/row number!\n";
            return;
        }

        Seat* temp = head[row - 1];
        for (int i = 1; i < seatNo; i++)
            temp = temp->next;

        if (!temp->booked) {
            cout << "Seat is not booked!\n";
        } else {
            temp->booked = false;
            cout << "Booking cancelled (Row " << row << ", Seat " << seatNo << ")!\n";
        }
    }
};


int main() {
    GalaxyMultiplex gm;
    int choice;

    cout << "\n🎬 Welcome to Galaxy Multiplex Ticket System 🎟️\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Seat Availability\n";
        cout << "2. Book Seats\n";
        cout << "3. Cancel Booking\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            gm.display();
            break;
        case 2:
            gm.bookMultipleSeats();
            break;
        case 3: {
            int row, seatNo;
            cout << "Enter row number (1–8): ";
            cin >> row;
            cout << "Enter seat number (1–8): ";
            cin >> seatNo;
            gm.cancelSeat(row, seatNo);
            break;
        }
        case 0:
            cout << "Thank you for using Galaxy Multiplex System!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
