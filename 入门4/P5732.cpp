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
    int n;
    cin >> n;
    
    vector<vector<int>> pascal(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        pascal[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            if (j == i) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << pascal[i][j];
            if (j < i) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
