
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef unsigned long long ull;
ull a[501] = {1};  

void solve(){
    int p;
    cin >> p;
    cout << (int)(p * log10(2)) + 1 << endl;
    for (; p > 0; p -= 60) {
        ull f = 0;  
        for (int i = 0; i < 500; i++) {
            if (p > 60)
                a[i] <<= 60;  
            else
                a[i] <<= p;  

            a[i] += f;  
            f = a[i] / 10;  
            a[i] %= 10;
        }
    }
    a[0] -= 1;
    for (int i = 499; i >= 0; i--) {
        putchar(a[i] + '0');  
        if (i % 50 == 0) putchar('\n');  
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}