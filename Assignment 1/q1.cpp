#include<iostream>
using namespace std;
int main() {
    int arr[100], n = 0, i, pos, val, found;
    int choice;

    while (true) {
        cout << "\n------MENU------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;

            case 2:
                cout << "Array elements are: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;

            case 3:
                cout << "Enter position (1 to " << n + 1 << "): ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;
                if (pos > n + 1 || pos <= 0) {
                    cout << "Invalid position!\n";
                } else {
                    for (i = n - 1; i >= pos - 1; i--) {
                        arr[i + 1] = arr[i];
                    }
                    arr[pos - 1] = val;
                    n++;
                    cout << "Inserted successfully.\n";
                }
                break;

            case 4:
                cout << "Enter position to delete (1 to " << n << "): ";
                cin >> pos;
                if (pos > n || pos <= 0) {
                    cout << "Invalid position!\n";
                } else {
                    for (i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    cout << "Deleted successfully.\n";
                }
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> val;
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == val) {
                        cout << "Element found at position " << i + 1 << endl;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    cout << "Element not found.\n";
                }
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}