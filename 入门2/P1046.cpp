#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const ll inf = 3e18;
const int maxn = 2e5 + 2;
const int maxm = 62;

void solve() {
    vector<int> v(10);
    for (int i = 0; i < 10; ++i) {
        cin >> v[i];
    }
    int T;
    cin >> T;
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        if (v[i] <= T + 30) {
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
