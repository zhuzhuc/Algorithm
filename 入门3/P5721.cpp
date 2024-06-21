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

void solve() {
    int n;
    cin >> n;
    int cnt=0; 
    for(int _=1;_<=n;_++)
    {
        for(int j=_;j<=n;j++)
        {
            cnt++;
            if(cnt<10)
            {
                cout << "0" << "";
            }
            cout << cnt << "";
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}