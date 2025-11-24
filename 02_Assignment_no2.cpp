#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter odd order n: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "This program supports odd n only.\n";
        return 0;
    }

    int magic[15][15] = {0};

    int i = 0, j = n/2, num = 1;
    while (num <= n*n) {
        magic[i][j] = num++;
        int newi = (i-1 + n) % n;
        int newj = (j+1) % n;
        if (magic[newi][newj] != 0)
            i = (i+1) % n;
        else {
            i = newi;
            j = newj;
        }
    }

    cout << "Magic Square:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << magic[i][j] << "\t";
        cout << "\n";
    }
    return 0;
}
