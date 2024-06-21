#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll Long Long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

void solve() {
    int T;
    cin >> T;
    vector<int> v(T);
    for (int i = 0; i < T; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}