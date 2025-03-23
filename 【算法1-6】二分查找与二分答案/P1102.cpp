#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<unordered_set>
#include<string>
#include<ctime>
#include<cstring>
#include<sstream>
#include<list>	
typedef long long ll;				
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
void solve1(){
	int n,c;
	cin >> n >> c;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	sort(v.begin(), v.end());
	unordered_map<i64, i64> num_count;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int A = v[i];
		int B = A - c;
		if (num_count.find(B) != num_count.end())
		{
			count += num_count[B];
		}
		num_count[A]++;
	}
	
	cout << count << "\n";
}
int binary_search1(vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r < a.size() && a[r] == x) return r;
    else return -1;
}
int binary_search2(vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l < a.size() && a[l] == x) return l;
    else return -1;
}

void solve2() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    sort(a.begin(), a.end()); 
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int A = a[i] + c;
        int res1 = binary_search1(a, A);
        if (res1 == -1) continue;
        else {
            int res2 = binary_search2(a, A);
            cnt += res2 - res1 + 1;
        }
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
	//solve1();
    solve2();
    cout<<fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
#endif
    

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
