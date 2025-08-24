#include<iostream>
using namespace std;
class diagonalMatrix {
    int arr[100];
    public:
    void insert(int size) {
        int arr_size = size;
        cout << "Enter the diagonal elements of your array: ";
        for(int i = 0; i < arr_size; i++) {
            cin >> arr[i];
        }

        return;
    }
    void get(int i, int j) {
        if(i==j) {
            cout << arr[i-1] << endl;
        }
        else {
            cout << "0";
        }

        return;
    }
};
int main() {
    diagonalMatrix ob;
    int n;

    cout << "Enter the size of your array: ";
    cin >> n;

    ob.insert(n);
    ob.get(2,2);
    ob.get(3,3);

    return 0;
}