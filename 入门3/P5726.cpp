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
    int n;
    cin >> n;

    vector<int> v(n);
    for (int _ = 0; _ < n; ++_) {
        cin >> v[_];
    }


    sort(v.begin(), v.end());


    v.erase(v.begin()); 
    v.pop_back();       


    double sum = accumulate(v.begin(), v.end(), 0);


    double average = sum / (n - 2);


    cout << fixed << setprecision(2) << average << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}