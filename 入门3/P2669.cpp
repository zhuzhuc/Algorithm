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

void printBigNumber(const vector<int>& num) {
    int start = num.size() - 1;
    while (start >= 0 && num[start] == 0) {
        --start;
    }
    if (start == -1) {
        cout << 0;
    } else {
        for (int i = start; i >= 0; --i) {
            cout << num[i];
        }
    }
    cout << endl;
}

void addBigNumbers(vector<int>& result, const vector<int>& num) {
    int carry = 0;
    for (size_t i = 0; i < num.size() || carry; ++i) {
        if (i == result.size()) {
            result.push_back(0);
        }
        result[i] += carry + (i < num.size() ? num[i] : 0);
        carry = result[i] / 10;
        result[i] %= 10;
    }
}
vector<int> multiplyBigNumbers(const vector<int>& num, int x) {
    vector<int> result(num.size(), 0);
    int carry = 0;
    for (size_t i = 0; i < num.size() || carry; ++i) {
        if (i == result.size()) {
            result.push_back(0);
        }
        long long current = result[i] + carry + (i < num.size() ? num[i] * 1LL * x : 0);
        result[i] = current % 10;
        carry = current / 10;
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}


void solve() {
    int k;
    cin >> k;

    int total_coins = 0;
    int current_day = 0;
    int n = 1;

    while (current_day < k) {
        int days_to_add = min(n, k - current_day);
        total_coins += days_to_add * n;
        current_day += days_to_add;
        n++;
    }

    cout << total_coins << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
