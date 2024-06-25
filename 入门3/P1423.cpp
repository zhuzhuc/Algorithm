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
    double s;
    cin >> s;
    int step = 0;
    double distance = 0.0;
    double step_lengrh = 2.0;
    while(distance < s){
        distance += step_lengrh;
        step_lengrh *= 0.98;
        step++;
    }
    cout << step << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}