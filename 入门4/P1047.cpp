#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

void solve() {
    int l, m;
    cin >> l >> m;
    
    vector<bool> road(l + 1, true); 

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; ++j) {
            road[j] = false;
        }
    }
    
    int remaining_trees = 0;
    for (int i = 0; i <= l; ++i) {
        if (road[i]) {
            remaining_trees++;
        }
    }
    
    cout << remaining_trees << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}