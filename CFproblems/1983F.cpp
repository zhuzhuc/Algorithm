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

int ch[3000042][2]{}, mx[3000042]{};
int nc = 1;

void insert(int root, int val, int idx) {
    int curr = root;
    for (int i = 29; i >= 0; i--) {
        int lr = ((val & (1 << i)) != 0);
        
        if (!ch[curr][lr]) {
            nc++;
            mx[nc] = idx;
            ch[curr][lr] = nc;
        }

        mx[curr] = max(mx[curr], idx);
        curr = ch[curr][lr];
    }

    mx[curr] = max(mx[curr], idx);
}

int query(int root, int mid, int val) {
    int curr = root;
    int idx = -1;

    for (int i = 29; i >= 0; i--) {
        if (!curr) return idx;

        // Check out with 1
        if ((val & (1 << i)) && (mid & (1 << i))) {
            if (ch[curr][1]) idx = max(idx, mx[ch[curr][1]]);
            curr = ch[curr][0];
        }
        else if ((val & (1 << i))) {
            curr = ch[curr][1];
        }
        else if ((mid & (1 << i))) {
            if (ch[curr][0]) idx = max(idx, mx[ch[curr][0]]);
            curr = ch[curr][1];
        }
        else {
            curr = ch[curr][0];
        }
    }

    if (curr) idx = max(idx, mx[curr]);

    return idx;
}

int v[100069]{};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int l = 0, r = (1 << 30) - 1, fin;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int left = -1;
            long long ans = 0;
            nc = 1;
            int root = nc;
            for (int i = 0; i < n; i++) {
                left = max(left, query(root, mid, v[i]));
                ans += ((long long)left + 1);
                insert(root, v[i], i);
            }

            for (int i = 0; i <= nc; i++) {
                ch[i][0] = 0;
                ch[i][1] = 0;
                mx[i] = 0;
            }

            if (ans < k) {
                l = mid + 1;
            }
            else {
                fin = mid;
                r = mid - 1;
            }
        }

        cout << fin << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
