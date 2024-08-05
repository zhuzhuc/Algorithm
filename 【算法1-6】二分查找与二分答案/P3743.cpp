#include <iostream>
#include <vector>
using namespace std;

int n; // 设备数量
double p; // 充电器的充电速度
vector<double> a, b; // 设备的能量消耗速度和初始能量
double lbound = 0, rbound = 1e10; // 二分查找的上下界
double sum = 0; // 所有设备的能量消耗速度总和

// 验证在给定时间内充电器是否能维持所有设备的运行
bool check(double ans) {
    double requiredEnergy = 0; // 需要的能量总和
    double maxEnergy = p * ans; // 充电器最多提供的能量

    for (int i = 0; i < n; i++) {
        double needed = a[i] * ans; // 设备在 ans 时间内需要的能量
        if (needed > b[i]) {
            requiredEnergy += (needed - b[i]); // 需要充电器补充的能量
        }
    }
    return requiredEnergy <= maxEnergy; // 比较需要的能量总和和充电器最多提供的能量
}

int main() {
    cin >> n >> p;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }

    // 如果所有设备的能量消耗速度总和小于等于充电器的充电速度，输出 -1
    if (sum <= p) {
        cout << -1.000000 << endl;
        return 0;
    }

    // 二分查找最大使用时间
    while (rbound - lbound > 1e-6) {
        double mid = (lbound + rbound) / 2;
        if (check(mid)) {
            lbound = mid;
        } else {
            rbound = mid;
        }
    }

    cout.precision(10);
    cout << fixed << lbound << endl;
    return 0;
}
