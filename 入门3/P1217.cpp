#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

bool is_palindrome(int x) {
    if (x < 10) return true;  // 单位数是回文数
    int original = x;
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

bool is_prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;  // 2是质数
    if (x % 2 == 0) return false;  // 其他偶数不是质数
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void find_prime_palindromes(int l, int r) {
    // 如果l是偶数，则将其调整为下一个奇数
    if (l % 2 == 0) ++l;

    // 遍历范围内的每一个奇数，检查是否是回文质数
    for (int num = l; num <= r; num += 2) {
        if (is_palindrome(num) && is_prime(num)) {
            cout << num << "\n";
        }
    }
}

int main() {
    int l, r;
    cin >> l >> r;
    find_prime_palindromes(l, r);
    return 0;
}