#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//
//
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const ll inf = 3e18;
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;

    int full_weeks = n / 7;    // 完整周数
    int remaining_days = n % 7; // 剩余的天数

    int work_days = full_weeks * 5; // 完整周数中的工作日总数

    // 计算剩余天数中的工作日数
    for (int i = 0; i < remaining_days; ++i) {
        int day = (x + i) % 7; // 模拟天数从 x 开始，遍历剩余天数
        if (day != 6 && day != 0) {
            work_days++;
        }
    }

    int total_distance = work_days * 250; // 计算总距离
    cout << total_distance << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}