#include <bits/stdc++.h>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll Long Long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;



int a[10001] = {};
int s[10001] = {};
int n, len = 1;


void solve() {
    
}


const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        // Calculate pow(9 // k + 1, r) % MOD
        long long base = 9 / k + 1;
        long long result_r = 1;
        while (r > 0) {
            if (r % 2 == 1) {
                result_r = (result_r * base) % MOD;
            }
            base = (base * base) % MOD;
            r /= 2;
        }
        
        // Calculate pow(9 // k + 1, l) % MOD
        long long result_l = 1;
        base = 9 / k + 1;
        while (l > 0) {
            if (l % 2 == 1) {
                result_l = (result_l * base) % MOD;
            }
            base = (base * base) % MOD;
            l /= 2;
        }
        
        // Calculate (result_r - result_l + MOD) % MOD
        long long answer = (result_r - result_l + MOD) % MOD;
        cout << answer << endl;
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
    
