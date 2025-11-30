#include<iostream>
#include<vector>
#include<string>
using namespace std;
void mySwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
bool isBetter(int a, int b, bool increasing) {
    if (increasing) {
        return a > b;  
    } else {
        return a < b;  
    }
}
void heapify(vector<int> &arr, int n, int i, bool increasing) {
    int extreme = i;     
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && isBetter(arr[left], arr[extreme], increasing)) {
        extreme = left;
    }
    if (right < n && isBetter(arr[right], arr[extreme], increasing)) {
        extreme = right;
    }
    if (extreme != i) {
        mySwap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}
void heapSort(vector<int> &arr, bool increasing) {
    int n = (int)arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, increasing);
    }
    for (int i = n - 1; i > 0; --i) {
        mySwap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter order (inc / dec): ";
    string order;
    cin >> order;

    bool increasing;
    if (order == "inc" || order == "INC" || order == "Inc") {
        increasing = true;
    } else {
        increasing = false;
    }

    heapSort(arr, increasing);

    if (increasing) {
        cout << "Sorted in increasing order:\n";
    } else {
        cout << "Sorted in decreasing order:\n";
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}