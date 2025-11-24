#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};


void push(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    if (source == NULL) {
        front = back = NULL;
        return;
    }

    if (source->next == NULL) {
      
        front = source;
        back = NULL;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    
    front = source;
    back = slow->next;
    slow->next = NULL;
}


int main() {
    Node* head = NULL;

    
    push(head, 2);
    push(head, 3);
    push(head, 5);
    push(head, 7);
    push(head, 11);

    cout << "Original List: ";
    printList(head);

    Node* front = NULL;
    Node* back = NULL;

    FrontBackSplit(head, front, back);

    cout << "\nFront List: ";
    printList(front);

    cout << "Back List: ";
    printList(back);

    // ✅ Test boundary cases
    cout << "\n--- Boundary Tests ---\n";

    // Case 1: Length = 1
    Node* single = new Node(10);
    FrontBackSplit(single, front, back);
    cout << "Length 1 -> Front: ";
    printList(front);
    cout << "Back: ";
    printList(back);

    // Case 2: Length = 2
    Node* two = NULL;
    push(two, 1);
    push(two, 2);
    FrontBackSplit(two, front, back);
    cout << "Length 2 -> Front: ";
    printList(front);
    cout << "Back: ";
    printList(back);

    // Case 3: Length = 3
    Node* three = NULL;
    push(three, 1);
    push(three, 2);
    push(three, 3);
    FrontBackSplit(three, front, back);
    cout << "Length 3 -> Front: ";
    printList(front);
    cout << "Back: ";
    printList(back);

    return 0;
}
