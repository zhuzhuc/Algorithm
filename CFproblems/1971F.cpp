#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};


void solve() {
    long long r;
    cin >> r;
    long long height = r;
    long long ans = 0;
    for (long long i = 0; i <= r; i++) {
        while (i * i + height * height >= (r + 1) * (r + 1)) {
            height--;
        }
        long long cop = height;
        while (i * i + cop * cop >= r * r && cop > 0) {
            cop--;
            ans++;
        }
    }
    cout << ans * 4 << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}