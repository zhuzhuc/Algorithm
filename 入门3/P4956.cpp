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
    long N;
    cin >> N;
    long x = N / 364L - 3L * max(1L, (N - 36400L) % 1092L ? (N - 36400L) / 1092L + 1L : (N - 36400L) / 1092L);
    long k = max(1L, (N - 36400L) % 1092L ? (N - 36400L) / 1092L + 1L : (N - 36400L) / 1092L);
    cout << x << endl << k << endl;
}
int main(int argc, char const *argv[])
{   

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
