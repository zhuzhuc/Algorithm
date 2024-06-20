#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};

void solve() {
    string s;
    cin >> s;

    int count = 1;  
    char last_char = s[0];  

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == last_char) {
            count++;
            if (count >= 7) {
                cout << "YES" << endl;
                return;
            }
        } else {
            last_char = s[i];
            count = 1;
        }
    }

    cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}