#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // 引入数学库以使用 sqrt 函数
using namespace std;
#define x first
#define y second


int main() {
    int n, X, Y;
    cin >> n >> X >> Y;

    vector<pair<int, int>> points; // 存储 (距离平方, 编号)
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        int dist = (x - X) * (x - X) + (y - Y) * (y - Y);
        points.emplace_back(dist, i);
    }

    sort(points.begin(), points.end());
    for (int i = 0; i < 3; ++i) {
        cout << points[i].second << endl;
    }

    return 0;
}
