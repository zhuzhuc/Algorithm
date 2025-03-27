#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> prime(ll n){
    map<ll, int> factors;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            factors[i]++;
            n /= i;
        }
    }
    if(n > 1) factors[n] = 1;
    return factors;
}
int main(){
    int q;cin >> q;
    while(q--){
        ll n,k;cin >> n >> k;
        map<ll,int> factors = prime(n);
        ll res = 1;
        for(auto [pre, ex] : factors){
            if(ex >= k){
                res *= pow(pre, ex);
            }
        }
        cout << res << "\n";
    }
    return 0;
}

