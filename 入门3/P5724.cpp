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
    vector<int> v(n);
    for (int _ = 0; _ < n; ++_) {
        cin >> v[_];
    }
    sort(v.begin(), v.end());
    int m = v.front();
    int j = v.back();
    cout << j - m << endl;
}
int main(int argc, char const *argv[])
{   

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
