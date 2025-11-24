#include <iostream>
using namespace std;


class Node {
public:
    int coeff;     
    int exp;       
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};


class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL;
    }

    
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);

        if (head == NULL || exp > head->exp) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->exp > exp)
            temp = temp->next;

        if (temp->next != NULL && temp->next->exp == exp) {
            
            temp->next->coeff += coeff;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

   
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "0";
            return;
        }
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != NULL)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    static Polynomial add(Polynomial p1, Polynomial p2) {
        Polynomial result;
        Node* t1 = p1.head;
        Node* t2 = p2.head;

        while (t1 != NULL && t2 != NULL) {
            if (t1->exp == t2->exp) {
                int sumCoeff = t1->coeff + t2->coeff;
                if (sumCoeff != 0)
                    result.insertTerm(sumCoeff, t1->exp);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->exp > t2->exp) {
                result.insertTerm(t1->coeff, t1->exp);
                t1 = t1->next;
            } else {
                result.insertTerm(t2->coeff, t2->exp);
                t2 = t2->next;
            }
        }

        
        while (t1 != NULL) {
            result.insertTerm(t1->coeff, t1->exp);
            t1 = t1->next;
        }
        while (t2 != NULL) {
            result.insertTerm(t2->coeff, t2->exp);
            t2 = t2->next;
        }

        return result;
    }
};


int main() {
    Polynomial p1, p2, sum;
    int n, coeff, exp;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        p1.insertTerm(coeff, exp);
    }

    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        p2.insertTerm(coeff, exp);
    }

    cout << "\nFirst Polynomial: ";
    p1.display();

    cout << "Second Polynomial: ";
    p2.display();

    sum = Polynomial::add(p1, p2);

    cout << "\nResultant Polynomial after Addition: ";
    sum.display();

    return 0;
}
