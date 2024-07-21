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
const int MAX_SIZE = 21;

int horse_moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};
void solve() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    

    vector<vector<long long>> dp(MAX_SIZE, vector<long long>(MAX_SIZE, 0));

    vector<vector<bool>> control(MAX_SIZE, vector<bool>(MAX_SIZE, false));

    control[hx][hy] = true;
    
    for (int i = 0; i < 8; i++) {
        int x = hx + horse_moves[i][0];
        int y = hy + horse_moves[i][1];
        if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE) {
            control[x][y] = true;
        }
    }
    
    dp[0][0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (control[i][j]) {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
