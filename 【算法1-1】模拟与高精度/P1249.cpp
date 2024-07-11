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



int a[10001] = {};
int s[10001] = {};
int n, len = 1;

void mul(int x) {
    for (int i = 1; i <= len; i++) s[i] *= x;
    for (int i = 1; i <= len; i++) {
        s[i+1] += s[i] / 10;
        s[i] %= 10;
    }
    while (s[len+1] > 0) {
        len++;
        s[len+1] += s[len] / 10;
        s[len] %= 10;
    }
}

void solve() {
    cin >> n;
    if (n == 3) {
        cout << 3 << endl;
        cout << 3 << endl;
        return;
    }
    if (n == 4) {
        cout << 4 << endl;
        cout << 4 << endl;
        return;
    }
    s[0] = s[1] = 1;
    int Sum = 0, tot = 0;
    for (int i = 2; Sum < n; Sum += i, i++) a[++tot] = i;
    if (Sum > n + 1) a[Sum - n - 1] = 0;
    else if (Sum == n + 1) {
        a[tot]++;
        a[1] = 0;
    }
    for (int i = 1; i <= tot; i++) {
        if (a[i]) {
            cout << a[i] << ' ';
            mul(a[i]);
        }
    }
    cout << endl;
    for (int i = len; i >= 1; i--) cout << s[i];
    cout << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}