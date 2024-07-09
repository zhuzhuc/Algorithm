#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int boy_count = 0, girl_count = 0;
    int n = s.size();

    for (int i = 0; i <= n; i++) {
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y')
        {
            boy_count++;
        }
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l')
        {
            girl_count++;
        }
    }

    cout << boy_count  << endl;
    cout << girl_count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
