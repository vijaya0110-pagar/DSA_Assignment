#include <iostream>
using namespace std;

class Node {
public:
    int bit; 
    Node* prev;
    Node* next;

    Node(int b) {
        bit = b;
        prev = next = NULL;
    }
};

class Binary {
public:
    Node* head;
    Node* tail;

    Binary() {
        head = tail = NULL;
    }

    
    void insertBit(int b) {
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

   
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

  
    Binary onesComplement() {
        Binary comp;
        Node* temp = head;
        while (temp != NULL) {
            comp.insertBit(temp->bit == 0 ? 1 : 0);
            temp = temp->next;
        }
        return comp;
    }

   
    Binary twosComplement() {
        Binary comp = onesComplement();
        Node* temp = comp.tail;
        int carry = 1;

        while (temp != NULL && carry == 1) {
            if (temp->bit == 0) {
                temp->bit = 1;
                carry = 0;
            } else {
                temp->bit = 0;
            }
            temp = temp->prev;
        }

        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = comp.head;
            comp.head->prev = newNode;
            comp.head = newNode;
        }
        return comp;
    }

    
    static Binary add(Binary b1, Binary b2) {
        Binary result;
        Node* t1 = b1.tail;
        Node* t2 = b2.tail;
        int carry = 0;

        while (t1 != NULL || t2 != NULL || carry != 0) {
            int bit1 = (t1 != NULL) ? t1->bit : 0;
            int bit2 = (t2 != NULL) ? t2->bit : 0;
            int sum = bit1 + bit2 + carry;

            result.insertFront(sum % 2);
            carry = sum / 2;

            if (t1) t1 = t1->prev;
            if (t2) t2 = t2->prev;
        }

        return result;
    }

   
    void insertFront(int b) {
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};


int main() {
    Binary num1, num2;

    int n;
    cout << "Enter number of bits in binary number 1: ";
    cin >> n;
    cout << "Enter bits (e.g., 1 0 1 1): ";
    for (int i = 0; i < n; i++) {
        int bit;
        cin >> bit;
        num1.insertBit(bit);
    }

    cout << "\nBinary Number 1: ";
    num1.display();

    
    Binary oneComp = num1.onesComplement();
    Binary twoComp = num1.twosComplement();

    cout << "1's Complement: ";
    oneComp.display();

    cout << "2's Complement: ";
    twoComp.display();

    
    cout << "\nEnter number of bits in binary number 2: ";
    cin >> n;
    cout << "Enter bits (e.g., 1 0 0 1): ";
    for (int i = 0; i < n; i++) {
        int bit;
        cin >> bit;
        num2.insertBit(bit);
    }

    cout << "\nBinary Number 2: ";
    num2.display();

    
    Binary sum = Binary::add(num1, num2);
    cout << "Addition Result: ";
    sum.display();

    return 0;
}
