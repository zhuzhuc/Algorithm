#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const ll inf = 3e18;
const int maxn = 2e5 + 2;
const int maxm = 62;

void solve() {
    int num[3],gcd;

    for(int i=0;i<3;i++)cin>>num[i];
    sort(num,num+3);
    for(gcd=num[0];gcd>1;gcd--)if(num[0]%gcd==0&&num[2]%gcd==0)break;
    cout<<num[0]/gcd<<"/"<<num[2]/gcd;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
