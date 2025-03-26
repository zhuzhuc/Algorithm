#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // 计算均值
    double mean = sum / n;

    // 计算方差
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (a[i] - mean) * (a[i] - mean);
    }
    variance /= n;

    // 计算标准差
    double std_dev = sqrt(variance);

    // 计算归一化结果并输出
    cout << fixed << setprecision(16);
    for (int i = 0; i < n; i++) {
        cout << (a[i] - mean) / std_dev << endl;
    }

    return 0;
}
