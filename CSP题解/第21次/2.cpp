#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    vector<pair<int, int>> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].x >> q[i].y;
    }
    
    sort(q.begin(), q.end());

    vector<vector<int>> s(2, vector<int>(n + 1, 0));
    
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i][j - 1] + (q[j - 1].y == i);
        }
    }
    
    int cnt = -1, res;
    for (int i = 1; i <= n; i++) {
        int t = s[0][i - 1] + s[1][n] - s[1][i - 1];
        if (t >= cnt) {
            cnt = t;
            res = q[i - 1].x;
        }
        while (i + 1 <= n && q[i].x == q[i - 1].x) {
            i++;
        }
    }
    
    cout << res << endl;
    return 0;
}
