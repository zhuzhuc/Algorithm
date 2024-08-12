#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> a(n, vector<int>(m));
    vector<string> s(n);
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    
    ll diff = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '1') {
                cur += 1;
                diff += a[i][j];
            } else {
                diff -= a[i][j];
            }
            pref[i + 1][j + 1] = pref[i][j + 1] + cur;
        }
    }
    
    if (diff == 0) {
        cout << "YES" << endl;
        return;
    }
    
    int g = 0;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= m - k; ++j) {
            int f = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j];
            f = abs(k * k - 2 * f);
            g = gcd(g, f);
        }
    }
    
    if (g == 0 || diff % g != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
