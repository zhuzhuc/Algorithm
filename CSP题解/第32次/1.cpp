#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int parent = 0; // 默认无上级
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // 跳过自己
            bool valid = true;
            for (int k = 0; k < m; k++) {
                if (a[j][k] <= a[i][k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (parent == 0 || j + 1 < parent) {
                    parent = j + 1; // 选择编号最小的
                }
            }
        }
        cout << parent << endl;
    }

    return 0;
}