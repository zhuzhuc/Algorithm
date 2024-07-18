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

int min_diff = INT_MAX;

// 使用DFS来遍历所有可能的组合
void dfs(int index, int n, int current_sour, int current_bitter, vector<pair<int, int>>& ingredients, bool used) {
    if (index == n) {
        if (used) {
            min_diff = min(min_diff, abs(current_sour - current_bitter));
        }
        return;
    }

    // 包含当前的食材
    dfs(index + 1, n, current_sour * ingredients[index].first, current_bitter + ingredients[index].second, ingredients, true);

    // 不包含当前的食材
    dfs(index + 1, n, current_sour, current_bitter, ingredients, used);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ingredients(n);
    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }

    // 初始调用DFS
    dfs(0, n, 1, 0, ingredients, false);

    // 输出最小的绝对差
    cout << min_diff << endl;

  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
