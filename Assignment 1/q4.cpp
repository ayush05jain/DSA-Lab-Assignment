#include <iostream>
using namespace std;
void reverseArray() {
    int arr[100], n, i, temp;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "Reversed Array: ";

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void matrixMultiplication() {
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and cols for first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and cols for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible.\n";
        return;
    }

    cout << "Enter first matrix:\n";

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter second matrix:\n";

    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Product Matrix:\n";

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
void transposeMatrix() {
    int a[10][10], trans[10][10], r, c, i, j;

    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            trans[j][i] = a[i][j];
        }
    }

    cout << "Transpose Matrix:\n";

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\n1. Reverse Array\n2. Matrix Multiplication\n3. Matrix Transpose\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) reverseArray();
        else if (choice == 2) matrixMultiplication();
        else if (choice == 3) transposeMatrix();
        else if (choice == 4) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}