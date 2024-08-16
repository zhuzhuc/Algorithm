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

void solve() {
    int N, M;
    cin >> N;

    list<int> lineup;
    lineup.push_back(1); // 将1号同学加入队列

    // 插入操作
    for (int i = 2; i <= N; ++i) {
        int k, p;
        cin >> k >> p;
        
        auto it = lineup.begin();
        while (*it != k) ++it; // 找到k号同学
        
        if (p == 0) { // 插入到左边
            lineup.insert(it, i);
        } else { // 插入到右边
            ++it;
            lineup.insert(it, i);
        }
    }
    
    // 读取移除操作
    cin >> M;
    unordered_set<int> removed;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        removed.insert(x);
    }

    // 输出剩余队列
    bool first = true;
    for (int student : lineup) {
        if (removed.find(student) == removed.end()) {
            if (!first) cout << " ";
            cout << student;
            first = false;
        }
    }
    cout << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
