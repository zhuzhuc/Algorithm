#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define MOD 1000000007 
#define do double

int gcd(int a, int b) { 
    return b == 0 ? abs(a) : gcd(b, a % b);
}


void solve() {
   do a,b,c;
   
   int t;
   cin >> a >> t;
   do am = a / t;
   b = t * 2;
   cout << fixed << setprecision(3);
   cout << am << endl; 
   cout << fixed << setprecision(0); 
   cout << b << endl;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    solve(); 

    return 0; 
}
