#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define db double

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void solve() {
    db a, b, c;
    db s, p;
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(1) << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
