#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
PII tree[1010];
int b[55][55];  // 藏宝图的大小不会超过 50x50
int INF = -1e8;

int main() {
    int n, L, S;
    cin >> n >> L >> S;
    for (int i = 0; i < n; i++) {
        cin >> tree[i].x >> tree[i].y;
    }

    int tc = 0;
    for (int i = S; i >= 0; i--) {
        for (int j = 0; j <= S; j++) {
            cin >> b[i][j];  // 注意 b[i][j] 以倒序方式输入
            tc += b[i][j];   // 统计藏宝图中 `1` 的数量
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int sx = tree[i].x, sy = tree[i].y;
        if (sx + S > L || sy + S > L) {
            continue;  // 避免越界
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int x = tree[j].x, y = tree[j].y;  // 这里原本写错了 y 的取值

            if (x >= sx && x - sx <= S && y >= sy && y - sy <= S) {  
                if (!b[x - sx][y - sy]) {
                    cnt = -INF;  // 任何不匹配的情况直接失败
                } else {
                    cnt++;
                }
            }
        }

        if (cnt == tc) res++;  // 必须完全匹配藏宝图中的 `1`
    }

    cout << res << endl;
    return 0;
}
