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
    int t = 0;
    int min;
    cin >> l >> m;
    
    std::vector<int> v;
    for (int i = 0; i < l; ++i)
    {
        cin >> v[i];
    }
    for (int _ = 1;_ < l - m + 1; ++_)
    {
        for(int j = 1; j <= m; j++){
            t+=v[_+j-1];
        }
        if (t < min)
        {
            /* code */min = t;
        }
    }
    cout << min << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}