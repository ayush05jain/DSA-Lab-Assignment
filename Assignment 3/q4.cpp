#include<iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;
    char c;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    while (infix[i] != '\0') {
        c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}