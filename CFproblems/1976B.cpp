#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
using li = long long;
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
int min_operations_to_transform(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int total_operations = 0;
    int diff = 0;  

    
    for (int i = 0; i < n; ++i) {
        diff += b[i] - a[i];
        total_operations += abs(b[i] - a[i]);
    }

   
    total_operations += abs(b[n] - (accumulate(a.begin(), a.end(), 0) + diff));

    return total_operations;
}
void solve() {
     int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<li> a(n), b(n + 1);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    li sum = 0, ext = 1e18;
    for (int i = 0; i < n; ++i) {
      sum += abs(a[i] - b[i]);
      ext = min(ext, abs(a[i] - b[n]));
      ext = min(ext, abs(b[i] - b[n]));
      if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i]))
        ext = 0;
    }
    cout << sum + ext + 1 << '\n';
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
