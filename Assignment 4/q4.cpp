#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<char> q;
    int freq[26] = {0};
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;

    return 0;
}