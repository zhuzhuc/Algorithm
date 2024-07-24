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
	int n;
	std::vector<ll> v;
    cin >> n;
    v.resize(n);
    for (auto &i : v)
    {
    	cin >> i;
    }
    for (int i = 0; i < n; ++i)
    {
    	if (v[i - 1] > 1 and v[i] == 1)
    	{
    		cout << "-1" << "\n";
    		return;
    	}
    }
    vector<ll> ops(n ,0);

    for (int i = 1; i < n; ++i)
    {
    	ll him = v[i - 1];
    	ll me = v[i];
    	ll extra = 0;
    	while(him!= 1 and him * him <= me){
    		extra -= 1, him *= him;
    	}
    	while(me < him){
    		extra++;
    		me *= me;
    	}
    	ops[i] = max(0ll, ops[i - 1] + extra);
    }
    ll ans = 0;
    for (auto i : ops)
    {
    	ans += i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t  =1;
    cin >> t;
    while(t--){solve();}
    return 0;
}
