#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define ss string

const int maxn = 2e5 + 2;
const int maxm = 62;

char shiftChar(char c, int n){
	return (c - 'a' + n) % 26 + 'a';
}
void solve() {
    int n;
    cin >> n;
    ss s;
    cin >> s;
    for (char &c : s)
    {
    	c = shiftChar(c, n);
    }
    cout << s << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}