#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define fk cerr<<"fk"<<endl
#define db(x) cerr<<(#x)<<'='<<(x)<<endl
#define db2(x,y) cerr<<(#x)<<'='<<(x)<<' '<<(#y)<<'='<<(y)<<endl
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define yes cout << "Yes" << "\n";
#define no cout << "No" << "\n";

void solve() {
    ll t,a[3000005], kmp[3000005];

map<char, int>m;
    string s;
    char b[3000005];
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        b[i + 1] = s[i];
    }
    kmp[0] = kmp[1] = 0;
    int j = 0;
    for (size_t i = 2; i <= n; i++)
    {
        while (j and b[j + 1] != b[i])
        {
            j = kmp[j];
        }
        if(b[j + 1] == b[i]){
            j += 1;
        }
        kmp[i] = j;
        
    }
    if(kmp[n] > n/2){
        yes;
        for (int i = 1; i <= kmp[n]; i++)
        {
            cout << b[i];
        }
        
    }
    else{
        no;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    solve();
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
#endif
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
