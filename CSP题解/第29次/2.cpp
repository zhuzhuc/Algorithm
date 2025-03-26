#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool check(int mid, const vector<int>& a, const vector<int>& b, int m, int k) {
    ll sum = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] > mid) {
            int reduce = min(a[i] - mid, a[i] - k);  // 不能缩减到小于k天
            sum += (ll)reduce * b[i];
            if(sum > m) return false;
        }
    }
    return sum <= m;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n), b(n);
    int max_t = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > max_t) max_t = a[i];
    }
    
    int l = k, r = max_t;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid, a, b, m, k)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5+1;
int n,m,k;
LL b[N];
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int t,c;
        cin >> t >> c;
        b[1] += c;
        b[t+1] -= c;
    }
    for(int i = 1; i < N; i++) b[i] += b[i - 1];
    LL cost = 0;
    int i = N - 1;
    while(i > k and cost + b[i] <= m) cost += b[i--];
    cout << i << endl;
    return 0;
}
*/