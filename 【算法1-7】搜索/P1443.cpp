#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define ms(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define WHILE(x) while(x)
#define CIN(x) cin >> x
#define COUT(x) cout << x << endl
#define LOG2(x) log2(x)
#define POW(x, y) pow(x, y)
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

struct Position{
    int x,y;
};
const int knmove[8][2] = {
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};
void bfs(int n, int m, int startX, int startY){
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<Position> q;
    q.push({startX, startY});
    distance[startX][startY] = 0;
    while(!q.empty()){
        Position pos = q.front();
        q.pop();
        for (auto move : knmove)
        {
            int newX = pos.x + move[0];
            int newY = pos.y + move[1];

            if (newX >= 0 and newX < n and newY >= 0 and newY < m and distance[newX][newY] == -1){
                distance[newX][newY] = distance[pos.x][pos.y] + 1;
                q.push({newX, newY});
            }
        }
    }
    for (const auto& row : distance)
    {
        for (const auto& cell : row)
        {
            if (cell == -1)
            {
                /* code */cout << -1 << "\t";
            }else{
                cout << cell << "\t";
            }
            cout << endl;
        }
    }
}
void solve() {
    int n,m,x,y;cin >> n >> m >> x >> y;
    x--;y--;
    bfs(n, m,x,y);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
