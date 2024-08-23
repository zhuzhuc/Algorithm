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

string words[20];
int use[20], maxLength = 0, n;

int canlink(string str1, string str2) {
    for (int i = 1; i < min(str1.length(), str2.length()); i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (str1[str1.length() - i + j] != str2[j]) {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return 0;
}

void solve(string currentStr, int currentLength) {
    maxLength = max(currentLength, maxLength);
    for (int i = 0; i < n; i++) {
        if (use[i] >= 2) continue;
        int overlapLength = canlink(currentStr, words[i]);
        if (overlapLength > 0) {
            use[i]++;
            solve(words[i], currentLength + words[i].length() - overlapLength);
            use[i]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    char startChar;
    cin >> startChar;

    fill(use, use + n, 0);

    for (int i = 0; i < n; i++) {
        if (words[i][0] == startChar) {
            use[i]++;
            solve(words[i], words[i].length());
            use[i]--;
        }
    }

    cout << maxLength;
    return 0;
}