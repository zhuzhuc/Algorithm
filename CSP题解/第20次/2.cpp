#include <iostream>
#include <vector>
using namespace std;

// 检查点 (x, y) 是否在矩形内
bool check(int x, int y, int xl, int yd, int xr, int yu) {
    return x >= xl && x <= xr && y >= yd && y <= yu;
}

int main() {
    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    int douliu = 0;  // 曾在高危区域逗留的人数
    int jinguo = 0;  // 经过高危区域的人数

    for (int i = 0; i < n; i++) {
        bool passed = false;  // 标记该居民是否经过高危区域
        int consecutive = 0;  // 连续位于高危区域的坐标数量
        bool stayed = false;  // 标记该居民是否曾在高危区域逗留

        for (int j = 0; j < t; j++) {
            int x, y;
            cin >> x >> y;
            if (check(x, y, xl, yd, xr, yu)) {
                passed = true;  // 该居民经过高危区域
                consecutive++;
                if (consecutive >= k) {
                    stayed = true;  // 该居民曾在高危区域逗留
                }
            } else {
                consecutive = 0;  // 连续计数重置
            }
        }

        if (passed) {
            jinguo++;
        }
        if (stayed) {
            douliu++;
        }
    }

    cout << jinguo << endl;
    cout << douliu << endl;
    return 0;
}