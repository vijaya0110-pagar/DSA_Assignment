#include <iostream>
using namespace std;

struct Triple {
    int row, col, val;
};

int main() {
    int m, n;
    int matrix[10][10];
    cout << "Enter number of rows and cols: ";
    cin >> m >> n;
    cout << "Enter matrix elements:\n";
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> matrix[i][j];

    Triple sparse[100];
    int count = 1; 
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j] != 0) {
                sparse[count].row = i;
                sparse[count].col = j;
                sparse[count].val = matrix[i][j];
                count++;
            }
        }
    }
    sparse[0].row = m;
    sparse[0].col = n;
    sparse[0].val = count-1;

    cout << "Sparse Matrix (row col val):\n";
    for (int i=0; i<count; i++)
        cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].val << "\n";


   
    Triple transpose[100];
    transpose[0].row = sparse[0].col;
    transpose[0].col = sparse[0].row;
    transpose[0].val = sparse[0].val;
    int k = 1;
    for (int col = 0; col < sparse[0].col; col++) {
        for (int i = 1; i <= sparse[0].val; i++) {
            if (sparse[i].col == col) {
                transpose[k].row = sparse[i].col;
                transpose[k].col = sparse[i].row;
                transpose[k].val = sparse[i].val;
                k++;
            }
        }
    }

    cout << "Transposed Sparse Matrix:\n";
    for (int i=0; i<k; i++)
        cout << transpose[i].row << " " << transpose[i].col << " " << transpose[i].val << "\n";

    return 0;
}
