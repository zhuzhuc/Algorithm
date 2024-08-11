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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> K(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }

    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    q.push({A, 0});
    visited[A] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == B) {
            cout << steps << endl;
            return;
        }

        int up = current + K[current];
        if (up <= N && !visited[up]) {
            q.push({up, steps + 1});
            visited[up] = true;
        }

        int down = current - K[current];
        if (down >= 1 && !visited[down]) {
            q.push({down, steps + 1});
            visited[down] = true;
        }
    }

    cout << -1 << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
