#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1), b(n + 1), w(n + 1, 0);

    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // 计算正常情况下的最小 w
    int w_min = a[0], curr_energy = w_min;
    for (int i = 1; i <= n; i++) {
        curr_energy -= a[i - 1];
        if (curr_energy < 0) {  // 如果能量不足，需要补足
            w_min += -curr_energy;
            curr_energy = 0;
        }
        curr_energy += b[i];  // 吸收补给
    }
    curr_energy -= a[n];  // 最后回到 0 号区域
    if (curr_energy < 0) w_min += -curr_energy;

    // 计算 w(i)
    for (int i = 1; i <= n; i++) {
        int w_i = w_min;
        curr_energy = w_min;
        for (int j = 1; j <= n; j++) {
            curr_energy -= a[j - 1];
            if (curr_energy < 0) {
                w_i += -curr_energy;
                curr_energy = 0;
            }
            if (j == i) continue;  // 第 i 号区域不补给
            curr_energy += b[j];
        }
        curr_energy -= a[n];
        if (curr_energy < 0) w_i += -curr_energy;
        w[i] = w_i;
    }

    // 输出 w(1), w(2), ..., w(n)
    for (int i = 1; i <= n; i++) {
        cout << w[i] << " ";
    }

    return 0;
}
