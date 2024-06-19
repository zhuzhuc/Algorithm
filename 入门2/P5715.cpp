
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    vector<int> v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < 3; ++i) {
        cout << v[i] << (i < 2 ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}