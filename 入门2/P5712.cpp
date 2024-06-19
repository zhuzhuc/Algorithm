
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve() {
    int x;
    cin >> x;
    if (x == 1)
    {
            cout << "Today, I ate 1 apple." << endl;
    }    
    else if ( x == 0)
    {
        cout << "Today, I ate 0 apple." << endl;
          
    }else{cout << "Today, I ate " << x << " " << "apples." << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}