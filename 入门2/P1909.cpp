#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = INT_MAX; 
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        int j, k, m, w;
        cin >> j >> k; 
        m = j;
        w = k;
        while (j < n) {
            j <<= 1;
            k <<= 1;
        } 
        while (j > n) {
            j -= m;
            k -= w;
        } 
        while (j < n) {
            j += m;
            k += w;
        } 
        if (k < ans) {
            ans = k;
        }
    }
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
