#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};


class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    void bubbleSort() {
        if (head == NULL)
            return;

        bool swapped;
        Node* temp;
        Node* last = NULL;

        do {
            swapped = false;
            temp = head;

            while (temp->next != last) {
                if (temp->data > temp->next->data) {
                    // Swap data
                    int t = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = t;
                    swapped = true;
                }
                temp = temp->next;
            }
            last = temp; 
        } while (swapped);
    }
};


int main() {
    DoublyLinkedList dll;
    int n, val;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insertEnd(val);
    }

    cout << "\nOriginal List: ";
    dll.display();

    dll.bubbleSort();

    cout << "Sorted List (Ascending Order): ";
    dll.display();

    return 0;
}
