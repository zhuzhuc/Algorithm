
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    if (b == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (c % b == 0)
    {
        cout << max(a - c / b, 0) << endl;
    }else{
        cout << max(a - c / b - 1, 0) << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}