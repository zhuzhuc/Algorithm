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
ll g(const string& a, ll b) {
    vector<ll> c;
    c.push_back(a.length());
    
    while (c.back() < b) {
        ll d = 2 * c.back() + 1;
        c.push_back(d);
    }
    
    return c.size() - 1;
}

char h(const string& a, ll b, ll k, const vector<ll>& c) {
    if (k == 0) {
        return a[b - 1];
    }

    ll d = c[k - 1];
    
    if (b <= d) {
        return h(a, b, k - 1, c);
    } else if (b == d + 1) {
        return a[c[0] % a.size()];
    } else {
        return h(a, b - d - 1, k - 1, c);
    }
}
void solve() {
    string s;ll i;
    ll n;
    cin >> s >> n;
    ll l = s.length();

    // 找到包括位置 n 的当前字符串长度
    while (l < n) {
        i = l;
        while (n > i) {
            i *= 2;  // 计算刚好包括 n 位置的串长
        }
        i /= 2;  // 得到当前串的一半长

        // 特殊处理：如果 n 位置是 i+1，那么经过下面这步操作后，n 变成了 0
        n -= (i + 1);
        if (n == 0) {
            n = i;
        }
    }

    // 输出第 n 个字符
    cout << s[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
