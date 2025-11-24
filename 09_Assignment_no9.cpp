#include <iostream>
using namespace std;

void bubbleSortWithPassAnalysis(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        bool swapped = false;
        cout << "Pass " << i+1 << ": ";
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            for (int k=0; k<n; k++) cout << arr[k] << " ";
            cout << "  ";
        }
        cout << "\n";
        if (!swapped) break;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[n];
    cout << "Enter marks:\n";
    for (int i=0; i<n; i++) cin >> marks[i];

    bubbleSortWithPassAnalysis(marks, n);

    cout << "Sorted marks with assigned roll nos:\n";
    for (int i=0; i<n; i++)
        cout << "Roll No " << i+1 << ": Marks " << marks[i] << "\n";

    return 0;
}
