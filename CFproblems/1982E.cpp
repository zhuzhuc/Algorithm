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
const int MOD = 1000000007;

map<pair<long long, int>, tuple<int, long long, long long>> mem;

tuple<int, long long, long long> calc(long long n, int k) {
    if (k < 0) {
        return tuple{0, 0ll, 0ll};
    }
    if (n == 1) {
        return tuple{1, 1ll, 1ll};
    }
    int bit = 63 - __builtin_clzll(n);
    long long mid = (1ll << bit);
    if (mid == n) {
        mid >>= 1;
        if (mem.count({n, k})) {
            return mem[{n, k}];
        }
    }
    auto [f1, s1, e1] = calc(mid, k);
    auto [f2, s2, e2] = calc(n - mid, k - 1);

    int sub1 = (e1 % MOD) * ((e1 + 1) % MOD) % MOD * 500000004 % MOD;
    f1 = (f1 * 1ll - sub1 + MOD) % MOD;
    int sub2 = (s2 % MOD) * ((s2 + 1) % MOD) % MOD * 500000004 % MOD;
    f2 = (f2 * 1ll - sub2 + MOD) % MOD;

    long long p = (e1 + s2) % MOD;
    int f_cur = (f1 * 1ll + f2 + (p * 1ll * ((p + 1) % MOD) % MOD * 500000004 % MOD)) % MOD;
    long long s_cur = s1;
    long long e_cur = e2;
    if (s1 == e1 && s1 != 0) {
        s_cur = (s1 + s2);
    }
    if (s2 == e2 && s2 != 0) {
        e_cur = (e1 + e2);
    }
    if ((mid << 1) == n) {
        mem[{n, k}] = tuple{f_cur, s_cur, e_cur};
    }
    return tuple{f_cur, s_cur, e_cur};
};

void solve() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        long long n;
        int k;
        cin >> n >> k;
        cout << get<0>(calc(n, k)) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
