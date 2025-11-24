#include <iostream>
using namespace std;

int main() {
    int n;
    int A[3][3], B[3][3], C[3][3];
    cout << "Enter size n: ";
    cin >> n;

    cout << "Enter elements of A:\n";
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> A[i][j];

    cout << "Enter elements of B:\n";
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> B[i][j];

    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            C[i][j] = 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            for (int k=0; k<n; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Result matrix C:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << C[i][j] << "\t";
        cout << "\n";
    }
    return 0;
}
