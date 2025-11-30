#include<iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char x) {
    if (top < 99) {
        top++;
        stack[top] = x;
    }
}
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}
int main() {
    char exp[100], temp;
    int i, flag = 1;

    cout << "Enter expression: ";
    cin >> exp;

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty()) {
                flag = 0;
                break;
            }
            temp = pop();
            if ((exp[i] == ')' && temp != '(') ||
                (exp[i] == '}' && temp != '{') ||
                (exp[i] == ']' && temp != '[')) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 1 && isEmpty()) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}