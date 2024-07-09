#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;  
    string document;
    cin >> document;  

    while (q--) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            string str;
            cin >> str;
            document += str;
            cout << document << endl;
        } else if (operation == 2) {
            int a, b;
            cin >> a >> b;
            document = document.substr(a, b);
            cout << document << endl;
        } else if (operation == 3) {
            int a;
            string str;
            cin >> a >> str;
            document.insert(a, str);
            cout << document << endl;
        } else if (operation == 4) {
            string str;
            cin >> str;
            size_t pos = document.find(str);
            if (pos == string::npos) {
                cout << -1 << endl;
            } else {
                cout << pos << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
