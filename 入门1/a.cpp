#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define MOD 1000000007 


int gcd(int a, int b) { 
    return b == 0 ? abs(a) : gcd(b, a % b);
}


void solve() {
    char c;
    cin >> c;
    if (islower(c))
    {
        char upper = toupper(c);
        cout << upper << endl;
    }
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    solve(); 

    return 0; 
}
