#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int PRN;
    string name;
    Node* next;

    Node(int p, string n) {
        PRN = p;
        name = n;
        next = NULL;
    }
};

class Club {
    Node* head;
public:
    Club() { head = NULL; }

    
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == NULL)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

   
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    
    void addMember(int prn, string name) {
        if (head == NULL) {
            cout << "First add President and Secretary!\n";
            return;
        }
        Node* newNode = new Node(prn, name);
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

   
    void deletePresident() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted!\n";
    }

    
    void deleteSecretary() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        cout << "Secretary deleted!\n";
    }

   
    void deleteMember(int prn) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->PRN != prn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Member not found!\n";
            return;
        }
        if (prev == NULL)
            head = head->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Member deleted!\n";
    }

   
    void display() {
        if (head == NULL) {
            cout << "No members in club!\n";
            return;
        }
        cout << "\n--- Vertex Club Members ---\n";
        Node* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << i++ << ". PRN: " << temp->PRN << "  Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    
    void countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total Members: " << count << endl;
    }

   
    void searchMember(int prn) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->PRN == prn) {
                cout << "Member Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found!\n";
    }

  
    void sortByPRN() {
        if (head == NULL)
            return;

        Node* i = head;
        while (i != NULL) {
            Node* j = i->next;
            while (j != NULL) {
                if (i->PRN > j->PRN) {
                    swap(i->PRN, j->PRN);
                    swap(i->name, j->name);
                }
                j = j->next;
            }
            i = i->next;
        }
        cout << "List sorted by PRN!\n";
    }

  
    void reverseList() {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed!\n";
    }

   
    void concatenate(Club &obj2) {
        if (head == NULL)
            head = obj2.head;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = obj2.head;
        }
        obj2.head = NULL; // optional, to avoid duplication
        cout << "Clubs concatenated!\n";
    }
};

int main() {
    Club divA, divB;
    int choice, prn;
    string name;

    do {
        cout << "\n--- Vertex Club Menu ---\n";
        cout << "1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n5. Delete Secretary\n6. Delete Member\n";
        cout << "7. Display Members\n8. Count Members\n9. Search Member\n10. Sort by PRN\n11. Reverse List\n12. Concatenate DivB into DivA\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            divA.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            divA.addSecretary(prn, name);
            break;
        case 3:
            cout << "Enter PRN & Name: ";
            cin >> prn >> name;
            divA.addMember(prn, name);
            break;
        case 4:
            divA.deletePresident();
            break;
        case 5:
            divA.deleteSecretary();
            break;
        case 6:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            divA.deleteMember(prn);
            break;
        case 7:
            divA.display();
            break;
        case 8:
            divA.countMembers();
            break;
        case 9:
            cout << "Enter PRN to search: ";
            cin >> prn;
            divA.searchMember(prn);
            break;
        case 10:
            divA.sortByPRN();
            break;
        case 11:
            divA.reverseList();
            break;
        case 12:
            cout << "Enter a few members for DivB first...\n";
            divB.addPresident(101, "Riya");
            divB.addMember(103, "Rohan");
            divB.addSecretary(105, "Sneha");
            divA.concatenate(divB);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
