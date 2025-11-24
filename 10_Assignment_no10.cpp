#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
    char name[20];
    int height;
    int weight;
    double average;
};

void merge(Employee arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    Employee L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int i=0; i<n2; i++) R[i] = arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i].average <= R[j].average) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(Employee arr[], int l, int r) {
    if(l<r) {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void selectionSort(Employee arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j].average < arr[min_idx].average)
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee arr[n];
    cout << "Enter name, height and weight:\n";
    for (int i=0; i<n; i++) {
        cin >> arr[i].name >> arr[i].height >> arr[i].weight;
        arr[i].average = (arr[i].height + arr[i].weight) / 2.0;
    }

    Employee arr1[n], arr2[n];
    for(int i=0; i<n; i++){
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    mergeSort(arr1,0,n-1);
    selectionSort(arr2,n);

    cout << "Sorted by merge sort:\n";
    for(int i=0;i<n;i++)
        cout << arr1[i].name << " " << arr1[i].average << "\n";

    cout << "Sorted by selection sort:\n";
    for(int i=0;i<n;i++)
        cout << arr2[i].name << " " << arr2[i].average << "\n";

    return 0;
}
