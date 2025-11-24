#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    
    void addStudent(string name) {
        Node* newNode = new Node(name);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

 
    bool contains(string name) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == name)
                return true;
            temp = temp->next;
        }
        return false;
    }

   
    int count() {
        int c = 0;
        Node* temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};


int main() {
    LinkedList cricket, football;
    int totalStudents;

    cout << "Enter total number of students in class: ";
    cin >> totalStudents;

    int n;
    string name;

    cout << "\nEnter number of students who like Cricket: ";
    cin >> n;
    cout << "Enter names of Cricket lovers:\n";
    for (int i = 0; i < n; i++) {
        cin >> name;
        cricket.addStudent(name);
    }

    cout << "\nEnter number of students who like Football: ";
    cin >> n;
    cout << "Enter names of Football lovers:\n";
    for (int i = 0; i < n; i++) {
        cin >> name;
        football.addStudent(name);
    }

    
    LinkedList both;
    Node* temp = cricket.head;
    while (temp != NULL) {
        if (football.contains(temp->name))
            both.addStudent(temp->name);
        temp = temp->next;
    }

    cout << "\n(a) Students who like BOTH Cricket and Football:\n";
    if (both.head == NULL)
        cout << "None\n";
    else
        both.display();

    
    LinkedList either;
    temp = cricket.head;
    while (temp != NULL) {
        if (!football.contains(temp->name))
            either.addStudent(temp->name);
        temp = temp->next;
    }

    temp = football.head;
    while (temp != NULL) {
        if (!cricket.contains(temp->name))
            either.addStudent(temp->name);
        temp = temp->next;
    }

    cout << "\n(b) Students who like EITHER Cricket OR Football (but not both):\n";
    if (either.head == NULL)
        cout << "None\n";
    else
        either.display();

   
    int neitherCount = totalStudents - (cricket.count() + football.count() - both.count());
    cout << "\n(c) Number of students who like NEITHER Cricket nor Football: " 
         << neitherCount << endl;

    return 0;
}
