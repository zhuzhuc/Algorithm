#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
const int N = 100010;
int n, a, b;

int main() {
    cin >> n >> a >> b;
    int sum = 0;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 计算重叠部分的边界
        int left = max(0, x1);
        int right = min(a, x2);
        int bottom = max(0, y1);
        int top = min(b, y2);
        // 判断是否有重叠
        if (left < right && bottom < top) {
            // 计算重叠部分的面积
            sum += (right - left) * (top - bottom);
        }
    }
    cout << sum << endl;
    return 0;
}