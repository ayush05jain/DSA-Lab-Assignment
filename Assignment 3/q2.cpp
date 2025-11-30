#include<iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char val) {
    top++;
    stack[top] = val;
}
char pop() {
    return stack[top--];
}
int main() {
    char str[100];
    int i;

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}