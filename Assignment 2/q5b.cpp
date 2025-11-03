#include<iostream>
using namespace std;
class triDiagonalMatrix{
    int arr[100];
    public:
    void insert(int size) {
        int arr_size = size;
        for(int i = 0; i < arr_size; i++) {
            cin >> arr[i];
        }
        
        return;
    }
    void get(int i) {
        cout << "Here is your element: " << arr[i-1] << endl;

        return;
    }
};
int main(){
    triDiagonalMatrix mainDiagonal, lowerDiagonal, upperDiagonal;
    int n;

    cout << "Enter the size of your array: ";
    cin >> n;

    cout << "Enter the elements for the main diagonal: \n";
    mainDiagonal.insert(n);

    cout << "Enter the elements of the upper diagonal: \n";
    upperDiagonal.insert(n-1);

    cout << "Enter the elements of the lower diagonal: \n";
    lowerDiagonal.insert(n-1);

    char ans;
    int rowAdd, columnAdd;

    cout << "Do you want to check your elements? (y/n): \n";
    cin >> ans;

    if(ans=='y') {
        cout << "Enter the row address of the element: \n";
        cin >> rowAdd;

        cout << "Enter the column address of the element: \n";
        cin >> columnAdd;

        if(rowAdd == columnAdd){
            mainDiagonal.get(rowAdd);
        }
        else if(rowAdd == columnAdd+1) {
            lowerDiagonal.get(columnAdd);
        }
        else if(rowAdd == columnAdd-1) {
            upperDiagonal.get(rowAdd);
        }
        else{
            cout << "0";
        }

    }

    return 0;        
}