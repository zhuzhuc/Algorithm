#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    long long sum  = 0;
    long long x = 0;
    for(int i = 0; i < n; i++){
        sum += max(a[i], b[i]);
        // ss[i] = min(a[i], b[i]);
        a[i] = min(a[i], b[i]);
  
    }
    
    sort(a.rbegin(), a.rend());
    // long long x = 0;
    for(int i = 0; i < min(k - 1, n); i++) x += a[i];
    cout << sum + x + 1 << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
