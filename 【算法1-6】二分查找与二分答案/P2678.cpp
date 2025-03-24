#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <set>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define LOCAL_DEFINE
#define MOD 1000000007
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;

int L, N, M;
vector<int> ro;

bool check(int dist) {
    int last = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (ro[i] - last < dist) cnt++;
        else last = ro[i];
    }
    if (L - last < dist) cnt++;
    return cnt <= M;
}

void solve() {
    cin >> L >> N >> M;
    ro.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> ro[i];
    sort(ro.begin(), ro.end());
    int lo = 1, hi = L + 1, mid;
    while (lo + 1 < hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
}

const int N_MAX = 1e6+1;
int a[N_MAX];

bool check2(int x, int n) {
    int i = 0, cnt = 0, nnow = 0;
    while (i < n) {
        while (i < n && a[i] - a[nnow] < x) {
            i++;
        }
        if (i < n) {
            nnow = i;
        }
    }
    if (L - a[nnow] < x) cnt++;
    return cnt <= M;
}

void solve2() {
    cin >> L >> N >> M;
    vector<int> ro(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> ro[i];
    }
    ro[N] = L; // 将 L 加入作为最后一个点
    int l = 1, r = L, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check2(mid, N)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();  // 选择运行 solve2
    return 0;
}
