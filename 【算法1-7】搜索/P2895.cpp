#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpi vector<pii>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)((x).size())
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mkp make_pair
#define fi first
#define se second
using namespace std;

constexpr int MAX_SIZE = 305;

int time1[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
int b1[4] = {0, 0, 1, -1}, b2[4] = {1, -1, 0, 0};

void solveCases() {
    int m;
    cin >> m;
    
    fill(&time1[0][0], &time1[0][0] + MAX_SIZE * MAX_SIZE, -1);  // 使用 fill 代替嵌套循环初始化
    fill(&c[0][0], &c[0][0] + MAX_SIZE * MAX_SIZE, 0);  // 重置访问标记

    queue<pii> meteors;
    
    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        meteors.push({x, y});
        time1[x][y] = (time1[x][y] == -1) ? t : min(time1[x][y], t);
        
        for (int j = 0; j < 4; ++j) {
            int nx = x + b1[j];
            int ny = y + b2[j];
            if (nx >= 0 && ny >= 0 && nx < MAX_SIZE && ny < MAX_SIZE) {
                time1[nx][ny] = (time1[nx][ny] == -1) ? t : min(time1[nx][ny], t);
            }
        }
    }
    
    queue<pii> q;
    q.push({0, 0});
    c[0][0] = 1;
    
    if (time1[0][0] == -1) {
        cout << 0 << endl;
        return;
    }
    
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        time++;
        
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + b1[i];
                int ny = y + b2[i];
                
                if (nx >= 0 && ny >= 0 && nx < MAX_SIZE && ny < MAX_SIZE && c[nx][ny] == 0) {
                    if (time1[nx][ny] == -1 || time < time1[nx][ny]) {
                        if (time1[nx][ny] == -1) {
                            cout << time << endl;
                            return;
                        }
                        c[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
    cout << -1 << endl;
}

signed main() {
    fastio;
    solveCases();
    return 0;
}
