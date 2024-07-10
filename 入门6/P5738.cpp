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

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; 
    if (n % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

double calculate(vector<int>& v) {
    int n = v.size();
    sort(v.begin(), v.end());
    double sum = accumulate(v.begin() + 1, v.end() - 1, 0);
    /*
    v.erase(v.begin());
    v.erase(v.end() - 1);
    double sum = accumulate(v.begin(), v.end(), 0);
    */
    return sum / (n - 2);
}

void solve() {
    int a, b;
    cin >> a >> b; 

    double ans = 0;
    for (int i = 0; i < a; ++i) {
        vector<int> v(b); 
        for (int j = 0; j < b; ++j) {
            cin >> v[j];
        }
        double aver = calculate(v);
        if (aver > ans) {
            ans = aver;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
