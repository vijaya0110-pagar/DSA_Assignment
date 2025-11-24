#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    quickSort(arr, low, i);
    quickSort(arr, i+2, high);
}

pair<int, int> findMinMax(int arr[], int low, int high) {
    if(low == high) return {arr[low], arr[high]};
    if(high == low+1) {
        if(arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }
    int mid = (low + high)/2;
    auto left = findMinMax(arr, low, mid);
    auto right = findMinMax(arr, mid+1, high);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[n];
    cout << "Enter marks:\n";
    for (int i=0; i<n; i++) cin >> marks[i];

    quickSort(marks, 0, n-1);
    cout << "Sorted marks: ";
    for (int i=0; i<n; i++) cout << marks[i] << " ";
    cout << "\n";

    auto minmax = findMinMax(marks, 0, n-1);
    cout << "Minimum marks: " << minmax.first << "\n";
    cout << "Maximum marks: " << minmax.second << "\n";

    return 0;
}
