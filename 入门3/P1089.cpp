#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

const int maxn = 2e5 + 2;
const int maxm = 62;
void solve() {
    int budget[12];
    for (int i = 0; i < 12; ++i) {
        cin >> budget[i];
    }

    int balance = 0;
    int savings = 0;
    for (int month = 0; month < 12; ++month) {
        balance += 300;
        if (balance < budget[month]) {
            cout << -(month + 1) << endl;
            return;
        }
        balance -= budget[month];
        int deposit = (balance / 100) * 100;
        savings += deposit;
        balance -= deposit;
    }

    cout << balance + savings * 1.2 << endl;
}
int main(int argc, char const *argv[])
{   

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
