#include <bits/stdc++.h>
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

void solve() {
    int usage; // 用电量
    double cost = 0.0;
    cin >> usage;

    if (usage <= 150) {
        cost = usage * 0.4463;
    } else if (usage <= 400) {
        cost = 150 * 0.4463 + (usage - 150) * 0.4663;
    } else {
        cost = 150 * 0.4463 + 250 * 0.4663 + (usage - 400) * 0.5663;
    }

    cout << fixed << setprecision(1) << cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
