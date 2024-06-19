#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define db double

void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int h,m;
    h = c - a;
    if (b > d)
    {
        h -= 1;/* code */
        m = 60 - b + d;
    }else{
        m = d - b;
    }
    cout << h << " " << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
