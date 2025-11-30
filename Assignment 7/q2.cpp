#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int min_idx = i, max_idx = i;
        for (int k = i; k <= j; k++) {
            if (arr[k] < arr[min_idx])
                min_idx = k;
            if (arr[k] > arr[max_idx])
                max_idx = k;
        }

        swap(arr[i], arr[min_idx]);

        if (max_idx == i)
            max_idx = min_idx;

        swap(arr[j], arr[max_idx]);

        i++;
        j--;
    }
}
int main() {
    int arr[100], n, i;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}