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
const int MAXN = 1e5 + 40;
int f[MAXN], siz[MAXN], q[MAXN];
int n, ans = 1e9, top = 0;
void solve() {
     cin >> n;

   
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    sort(f + 1, f + n + 1);
    q[0] = 1e9 + 1;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = top;
       
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (f[i] >= q[mid]) l = mid;
            else r = mid - 1;
        }
        
        if (q[l] != f[i]) {
            siz[++top] = 1;
            q[top] = f[i] + 1;
        } else {
            siz[l]++;
            q[l]++;
        }
    }

    
    for (int i = 1; i <= top; i++) {
        ans = min(ans, siz[i]);
    }

   
    cout << ans  << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
