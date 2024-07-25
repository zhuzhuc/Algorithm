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
struct tuple_hash {
    template <class T1, class T2, class T3>
    size_t operator()(const tuple<T1, T2, T3>& t) const {
        auto hash1 = hash<T1>{}(get<0>(t));
        auto hash2 = hash<T2>{}(get<1>(t));
        auto hash3 = hash<T3>{}(get<2>(t));
        return hash1 ^ hash2 ^ hash3;
    }
};

unordered_map<tuple<int, int, int>, ll, tuple_hash> memo;

ll w(int a, int b, int c) {

    a = max(a, 0);
    b = max(b, 0);
    c = max(c, 0);

    tuple<int, int, int> key = make_tuple(a, b, c);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    ll res;

    if (a <= 0 || b <= 0 || c <= 0) {
        res = 1;
    } else if (a > 20 || b > 20 || c > 20) {
        res = w(20, 20, 20);
    } else if (a < b && b < c) {
        res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    memo[key] = res;
    return res;
}

void solve() {
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
/*
ll memory[21][21][21];

ll w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (memory[a][b][c] != -1) {
        return memory[a][b][c];
    }
    if (a < b && b < c) {
        memory[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        memory[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return memory[a][b][c];
}

void solve() {
    memset(memory, -1, sizeof(memory));  // 初始化记忆数组
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
 */
/*
LL dp[25][25][25];

LL w(LL a, LL b, LL c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (dp[a][b][c] != 0) return dp[a][b][c];

    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    return dp[a][b][c];
}

int main() {
    LL a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) == 3) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}
 */