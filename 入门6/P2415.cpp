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
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) return false;}
    return true;
}
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1; 
    }
    return n * factorial(n - 1);
}
void solve() {
    std::vector<int> v;
    int n;
    while(cin >> n){
    	v.push_back(n);
    }
    int m = v.size();
    ll sum = 0;

    ll factor = pow(2, m -1);
    for (int i = 0; i < m; ++i)
    {
    	sum += v[i] * factor;
    }
    cout << sum << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}