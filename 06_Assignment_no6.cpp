#include <iostream>
using namespace std;

struct Student {
    char name[20];
    int roll_no;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student arr[n];
    cout << "Enter name and roll number:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].roll_no;

    for (int i = 0; i < n; i++) {
        if (arr[i].roll_no == 17 && strcmp(arr[i].name, "XYZ") == 0) {
            cout << "Student found: " << arr[i].name << " Roll No: " << arr[i].roll_no << "\n";
            return 0;
        }
    }
    cout << "Student not found.\n";
    return 0;
}
