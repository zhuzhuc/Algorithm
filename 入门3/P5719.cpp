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
    int n, k;
    cin >> n >> k;

    long long sumA = 0, sumB = 0;
    int countA = 0, countB = 0;

    for (int i = 1; i <= n; ++i) {
        if (i % k == 0) {
            sumA += i;
            ++countA;
        } else {
            sumB += i;
            ++countB;
        }
    }

    double avgA = countA == 0 ? 0 : (double)sumA / countA;
    double avgB = countB == 0 ? 0 : (double)sumB / countB;

    cout << fixed << setprecision(1) << avgA << " " << avgB << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}