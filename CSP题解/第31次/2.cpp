#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<double> k(N), t(N);
    k[0] = 1.0; // 初始化
    t[0] = 0.0;

    for (int i = 1; i <= n; i++) { // 从1开始
        int op;
        double val;
        cin >> op >> val;
        if (op == 1) {
            k[i] = k[i - 1] * val;
            t[i] = t[i - 1];
        } else {
            k[i] = k[i - 1];
            t[i] = t[i - 1] + val;
        }
    }

    while (m--) {
        int i, j;
        double x, y; // 直接读为double
        cin >> i >> j >> x >> y;

        double ktotal = k[j] / k[i - 1];
        double thetatotal = t[j] - t[i - 1];

        // 拉伸
        x *= ktotal;
        y *= ktotal;

        // 旋转
        double dx = x * cos(thetatotal) - y * sin(thetatotal);
        double dy = x * sin(thetatotal) + y * cos(thetatotal);

        cout << fixed << setprecision(3) << dx << " " << dy << "\n";
    }

    return 0;
}