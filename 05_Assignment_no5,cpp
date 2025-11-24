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

    int row_terms[10] = {0}, start_pos[10];
    Triple transpose[100];
    int num = sparse[0].val;
    int ncols = sparse[0].col;

    transpose[0].row = ncols;
    transpose[0].col = sparse[0].row;
    transpose[0].val = num;

    for(int i=1; i<=num; i++)
        row_terms[sparse[i].col]++;

    start_pos[0] = 1;
    for(int i=1; i<ncols; i++)
        start_pos[i] = start_pos[i-1] + row_terms[i-1];

    for(int i=1; i<=num; i++){
        int col = sparse[i].col;
        int pos = start_pos[col]++;
        transpose[pos].row = sparse[i].col;
        transpose[pos].col = sparse[i].row;
        transpose[pos].val = sparse[i].val;
    }

    cout << "Fast Transpose:\n";
    for (int i=0; i<=num; i++)
        cout << transpose[i].row << " " << transpose[i].col << " " << transpose[i].val << "\n";

    return 0;
}
