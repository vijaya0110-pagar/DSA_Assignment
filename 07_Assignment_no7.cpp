#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[20];
    int roll_no;
    int total_marks;
};

void bubbleSort(Student a[], int n, int &swapcount) {
    swapcount = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (a[j].roll_no > a[j+1].roll_no) {
                Student temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapcount++;
            }
        }
    }
}

int partition(Student a[], int low, int high, int &swapcount) {
    int pivot = a[high].roll_no;
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j].roll_no <= pivot){
            i++;
            Student temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            swapcount++;
        }
    }
    Student temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    swapcount++;
    return i+1;
}

void quickSort(Student a[], int low, int high, int &swapcount) {
    if (low < high) {
        int pi = partition(a, low, high, swapcount);
        quickSort(a, low, pi-1, swapcount);
        quickSort(a, pi+1, high, swapcount);
    }
}

int main() {
    int n, swapBubble, swapQuick;
    cout << "Enter number of students: ";
    cin >> n;
    Student arr[n];
    cout << "Enter student name, roll no., total marks:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].roll_no >> arr[i].total_marks;

    Student arrBubble[n], arrQuick[n];
    for(int i=0; i<n; i++) {
        arrBubble[i] = arr[i];
        arrQuick[i] = arr[i];
    }

    bubbleSort(arrBubble, n, swapBubble);
    quickSort(arrQuick, 0, n-1, swapQuick);

    cout << "Bubble Sort swaps: " << swapBubble << "\n";
    cout << "Quick Sort swaps: " << swapQuick << "\n";

    return 0;
}
