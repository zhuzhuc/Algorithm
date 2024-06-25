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
int reverse_number(int n) {
    bool is_negative = (n < 0);
    n = abs(n);  // 取绝对值进行反转

    int reversed_num = 0;
    while (n > 0) {
        reversed_num = reversed_num * 10 + n % 10;
        n /= 10;
    }

    if (is_negative) {
        reversed_num = -reversed_num;  // 如果原数是负数，结果也是负数
    }

    return reversed_num;
}

int main() {
    int N;
    cin >> N;

    int result = reverse_number(N);
    cout << result << endl;

    return 0;
}