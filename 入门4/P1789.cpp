#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;
void solve() {
     int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    //fire
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--; 
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n) {
                    if (abs(dx) + abs(dy) <= 2) { 
                        grid[x+dx][y+dy] = true;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--; 
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n) {
                    grid[x+dx][y+dy] = true;
                }
            }
        }
    }
    int dark_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!grid[i][j]) {
                dark_count++;
            }
        }
    }
    
    cout << dark_count << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
