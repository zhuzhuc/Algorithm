#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) return false;}
    return true;
}


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);  
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }   
    
    vector<int> primes;
    for (int i : v) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (size_t i = 0; i < primes.size(); ++i) {
        
        cout << primes[i] << " ";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}