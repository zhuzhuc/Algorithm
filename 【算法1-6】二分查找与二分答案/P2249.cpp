#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>

#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <functional>
#include <climits>
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

// void solve1() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<int> array(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> array[i];
//     }

//     for (int i = 0; i < m; ++i) {
//         int query;
//         cin >> query;

//         auto it = lower_bound(array.begin(), array.end(), query);
        
//         if (it != array.end() && *it == query) {
//             cout << (it - array.begin() + 1) << " "; 
//         } else {
//             cout << -1 << " "; 
//         }
//     }
//     cout << endl;
// }
bool isBlue(int num, int x){
    if(num < x) return true;
    else return false;
}
int binarySearch(const vector<int>& array, int len, int x) {
    int l = 0, r = len + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;  
        if (array[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r < len && array[r] == x) return r;  
    return -1;
}

void solve2() {
    int n, m;
    cin >> n >> m;
    vector<int> array(n);
    for (int i = 1; i <= n; ++i) {  
        cin >> array[i];
    }
    while (m--) {
        int x;
        cin >> x;
        cout << binarySearch(array, n, x) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve2();
    return 0;
}