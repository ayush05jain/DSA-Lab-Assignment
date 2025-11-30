#include <iostream>
using namespace std;
int main() {
    int arr[10][10];
    int r, c, i, j, sum;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    cout << "Enter matrix elements:\n";

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nRow Sums:\n";

    for (i = 0; i < r; i++) {
        sum = 0;
        for (j = 0; j < c; j++) {
            sum = sum + arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }

    cout << "\nColumn Sums:\n";

    for (j = 0; j < c; j++) {
        sum = 0;
        for (i = 0; i < r; i++) {
            sum = sum + arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }

    return 0;
}