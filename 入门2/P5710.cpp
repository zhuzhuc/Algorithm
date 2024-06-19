
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    int x;
    cin >> x;
    
    int a = (x % 2 == 0 && x > 4 && x <= 12);

    int u = (x % 2 == 0 || (x > 4 && x <= 12));

    int b = (x % 2 == 0) != (x > 4 && x <= 12); 

    int z = (x % 2 != 0 && !(x > 4 && x <= 12));
    
    cout << a << " " << u << " " << b << " " << z << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}