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

ll powerOfTwo(int k) {
    ll result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= 2;
    }
    return result;
}

void solve(ll princessX, ll princessY, ll startX, ll startY, ll size) {
    if (size == 1) return; 

    ll halfSize = size / 2;
    ll centerX = startX + halfSize;
    ll centerY = startY + halfSize;


    if (princessX < centerX && princessY < centerY) {
 
        printf("%lld %lld 1\n", centerX, centerY);
        solve(princessX, princessY, startX, startY, halfSize);
        solve(centerX - 1, centerY, startX, centerY, halfSize);
        solve(centerX, centerY - 1, centerX, startY, halfSize);
        solve(centerX, centerY, centerX, centerY, halfSize);
    } else if (princessX < centerX && princessY >= centerY) {

        printf("%lld %lld 2\n", centerX, centerY - 1);
        solve(centerX - 1, centerY - 1, startX, startY, halfSize);
        solve(princessX, princessY, startX, centerY, halfSize);
        solve(centerX, centerY - 1, centerX, startY, halfSize);
        solve(centerX, centerY, centerX, centerY, halfSize);
    } else if (princessX >= centerX && princessY < centerY) {

        printf("%lld %lld 3\n", centerX - 1, centerY);
        solve(centerX - 1, centerY - 1, startX, startY, halfSize);
        solve(centerX - 1, centerY, startX, centerY, halfSize);
        solve(princessX, princessY, centerX, startY, halfSize);
        solve(centerX, centerY, centerX, centerY, halfSize);
    } else {
        printf("%lld %lld 4\n", centerX - 1, centerY - 1);
        solve(centerX - 1, centerY - 1, startX, startY, halfSize);
        solve(centerX - 1, centerY, startX, centerY, halfSize);
        solve(centerX, centerY - 1, centerX, startY, halfSize);
        solve(princessX, princessY, centerX, centerY, halfSize);
    }
}

void solve() {
    int k;
    ll x, y;
    scanf("%d %lld %lld", &k, &x, &y);
    ll size = powerOfTwo(k);
    solve(x, y, 1, 1, size);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
