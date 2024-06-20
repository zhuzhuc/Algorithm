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
    int k, n, w;
    cin >> k >> n >> w;
    long long totalCost = k * w * (w + 1) / 2;
    if (totalCost <= n) {
        cout << 0 << endl;
    } else {
        cout << totalCost - n << endl;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}