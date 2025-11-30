#include <iostream>
#include <stack>
using namespace std;
int main() {
    char exp[100];
    int i, op1, op2, res;
    stack<int> s;

    cout << "Enter Postfix Expression: ";
    cin >> exp;

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            s.push(exp[i] - '0');
        } else {
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (exp[i]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }
            s.push(res);
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}