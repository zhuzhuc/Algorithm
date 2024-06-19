
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    int x;
    cin >> x;
    if ((x % 400 == 0) || (x % 4 == 0 && x % 100 != 0) )
    {
        cout << "1" << "\n";
    }else{cout << "0" << "\n";}
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}