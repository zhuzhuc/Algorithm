#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const ll inf = 3e18;
const int maxn = 2e5 + 2;
const int maxm = 62;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

void solve() {
    int wa, TLE, PE;
    cin >> wa >> TLE >> PE;
    vector<vector<int>> mat(wa, vector<int>(TLE));
    vector<bitset<maxn>> bs(TLE);
    vector<ll> mask(wa, 0);
    bitset<maxn> RE;
    for (int i = 0; i < wa; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < TLE; j++) {
            mat[i][j] = s[j] - '0';
            if (mat[i][j]) {
                mask[i] += (1ll << j);
                bs[j].set(i);
            }
        }
    }

    int ans = 0;
    string res(TLE, '0');
    for (int _ = 0; _ < 7; _++) {
        int i = rand(0, wa - 1);
        for (ll sub = mask[i]; sub; sub = (sub - 1) & mask[i]) {
            RE.set();
            int q = 0;
            for (int b = 0; b < TLE; b++) {
                if (sub & (1ll << b)) {
                    RE &= bs[b];
                    q++;
                }
            }
            if (RE.count() >= (wa + 1) / 2 && q > ans) {
                ans = q;
                for (int b = 0; b < TLE; b++) {
                    if (sub & (1ll << b)) {
                        res[b] = '1';
                    } else {
                        res[b] = '0';
                    }
                }
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
