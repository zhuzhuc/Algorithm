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

string multiply(string num1, int num2) {
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        int product = (num1[i] - '0') * num2 + carry;
        num1[i] = (product % 10) + '0';
        carry = product / 10;
    }
    while (carry) {
        num1.insert(num1.begin(), (carry % 10) + '0');
        carry /= 10;
    }
    return num1;
}

string factorial(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }
    return result;
}

int count_digit(const string& number, char digit) {
    return count(number.begin(), number.end(), digit);
}

const int N = 2e5 + 5;

int n, k, d[2 * N];

void solve() {
    int t;
    cin >> t;
 
    while (t--) {
        cin >> n >> k;
 
        int mx = -1;
        fill(d, d + 2 * k, 0);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            assert(x >= 1);
            d[x % (2 * k)]++;
            mx = max(mx, x);
        }
 
        int cnt = 0;
        int ans = INT_MAX;
        for (int i = 0; i <= k - 2; i++) {
            cnt += d[i];
        }
 
        for (int l = 0, r = k - 1; l < 2 * k; l++, r++) {
            if (r >= 2 * k) r -= 2 * k;
 
            if (cnt += d[r]; cnt == n) {
                int wait = (r - mx) % (2 * k);
                if (wait < 0) wait += 2 * k;
                ans = min(ans, mx + wait);
            }
 
            cnt -= d[l];
        }
 
        if (ans == INT_MAX) {
            ans = -1;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
